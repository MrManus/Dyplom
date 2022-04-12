/*
 * parser_complex.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Manus
 */
#include "main.h"
#include "utils.h"
#include "ring_buffer.h"
#include "parser_comlex.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

static char MyName[32] = "No Name";


void Parser_TakeLine(RingBuffer_t *Buf, uint8_t *Destination)
{
	uint8_t Tmp;
	uint8_t i = 0;
	  do
	  {
		  RB_Read(Buf, &Tmp);
		  if(Tmp == ENDLINE)
		  {
			  Destination[i] = 0;
		  }
		  else
		  {
			  Destination[i] = Tmp;
		  }
		  i++;
	  }while(Tmp != ENDLINE);
}


//
// LED=
//		0
//		1

static void Parser_ParseLED(uint8_t *LEDStatus)
{
//	String to parse:
//	0
//	1

	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0)
	{
		if(ParsePointer[0] < '0' || ParsePointer[0] > '1')
		{
			UartLog("LED wrong value. Please type 0 or 1!\r\n");
			return;
		}

		if(ParsePointer[0] == '1')
		{
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			UartLog("LED On\n\r");
			*LEDStatus = 1;

		}
		else if(ParsePointer[0] == '0')
		{
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			UartLog("LED Off\n\r");
			*LEDStatus = 0;
		}
	}
}

//	ENV=
//		X,Y,Z

static void Parser_ParseENV(void)
{
	// X,Y,Z - float
	uint8_t i, j;
	float EnvParameters[3];
	char Message[32];

	for(i = 0; i < 3; i++)
	{
		char *ParsePointer = strtok(NULL, ",");

		if(strlen(ParsePointer) > 0)
		{
//			X.XX <- i = 0
//			Y.YY <- i = 1
//			Z.ZZ <- i = 2

			for(j = 0; ParsePointer[j] !=0; j++)
			{
				if((ParsePointer[j] < '0' || ParsePointer[j] > '9') && ParsePointer[j] != '.')
				{
					UartLog("ENV wrong value. Don't use letters dude!\r\n");
					return;
				}
			}
			EnvParameters[i] = atof(ParsePointer); //atof - zamienia ascii na float
		}
		else
		{
			UartLog("ENV too few values. ENV=X,Y,Z\\n\r\n");
			return;
		}
	}

	sprintf(Message, "Temperature: %.1f\r\n", EnvParameters[0]);
	UartLog(Message);

	sprintf(Message, "Humidity: %.1f\r\n", EnvParameters[1]);
	UartLog(Message);

	sprintf(Message, "Pressure: %.1f\r\n", EnvParameters[2]);
	UartLog(Message);
}

// NAME=
//		STRING
//		?

static void Parser_ParseNAME(void)
{
//	STRING <- Rename device
//	? <- Introduce device

	char Message[64];

	char *ParsePointer = strtok(NULL, ",");

	if(strlen(ParsePointer) > 0)
	{
		if(strcmp("?", ParsePointer) == 0)
		{
			sprintf(Message, "My name is %s\r\n", MyName);
			UartLog(Message);
		}
		else
		{
			if(strlen(ParsePointer) > 32)
			{
				UartLog("Name should be smaller than 32 characters\r\n");
				return;
			}

			strcpy(MyName, ParsePointer);
			sprintf(Message, "My new name is %s\r\n", MyName);
			UartLog(Message);
		}
	}
	else
	{
		UartLog("Name cannot be empty!\r\n");
	}

}

void Parser_Parse (uint8_t *DataToParse, uint8_t *LEDStatus)
{
	char *ParsePointer = strtok((char*)DataToParse, "=");

	if(strcmp("LED", ParsePointer) == 0)
	{
	  Parser_ParseLED(LEDStatus);
	}
	else if(strcmp("ENV", ParsePointer) == 0)
	{
	  Parser_ParseENV();
	}
	else if(strcmp("NAME", ParsePointer) == 0)
	{
	  Parser_ParseNAME();
}
}
