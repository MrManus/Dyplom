/*
 * parser_simple.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Manus
 */
#include "main.h"
#include "utils.h"
#include "ring_buffer.h"
#include "parser_simple.h"
#include "string.h"


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


void Parser_Parse (uint8_t *DataToParse)
{
	  //
	  // LED_ON\n
	  // LED_OFF\n

	  if(strcmp("LED_ON", (char*)DataToParse) == 0)
	  {
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
		  UartLog("LED On\n\r");
	  }
	  else if(strcmp("LED_OFF", (char*)DataToParse) == 0)
	  {
		  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		  UartLog("LED Off\n\r");
	  }
}
