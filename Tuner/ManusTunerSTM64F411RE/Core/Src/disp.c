
#include <float.h>
#include <stdint.h>
#include "main.h"
#include "frequencies.h"
#include "disp.h"
#include "disp_chars.h"

#define MAX7219_NOOP_REGISTER   0x00
#define MAX7219_DIGIT0_REGISTER 0x01
#define MAX7219_DIGIT1_REGISTER 0x02
#define MAX7219_DIGIT2_REGISTER 0x03
#define MAX7219_DIGIT3_REGISTER 0x04
#define MAX7219_DIGIT4_REGISTER 0x05
#define MAX7219_DIGIT5_REGISTER 0x06
#define MAX7219_DIGIT6_REGISTER 0x07
#define MAX7219_DIGIT7_REGISTER 0x08
#define MAX7219_DECODE_MODE_REGISTER  0x09
#define MAX7219_INTENSITY_REGISTER   0x0A
#define MAX7219_SCAN_LIMIT_REGISTER   0x0B
#define MAX7219_SHUTDOWN_REGISTER    0x0C
#define MAX7219_DISPLAY_TEST_REGISTER 0x0F

typedef union
{
	struct
	{
		uint8_t		val:	8;
		uint8_t 	addr:	4;
		uint8_t		dummy:  4;
	}__attribute__((packed));
	uint16_t raw;
}display_frm_u;

typedef enum
{
	NoDecode 		= 0,
	DecodeFor0		= 1,
	DecodeFor3_0	= 2,
	DecodeFor7_0	= 3
}MAX7219_DecodeMode;

typedef enum
{
	SleepMode 		= 0,
	NormalOperation	= 1
}MAX7219_ShutdownMode;

typedef enum
{
	TestOff		= 0,
	TestMode	= 1
}MAX7219_TestMode;

typedef enum
{
	ScanDigit0		= 0,
	ScanDigit0_1	= 1,
	ScanDigit0_2	= 2,
	ScanDigit0_3	= 3,
	ScanDigit0_4	= 4,
	ScanDigit0_5	= 5,
	ScanDigit0_6	= 6,
	ScanDigit0_7	= 7,
}MAX7219_ScanLimit;

SPI_HandleTypeDef* disp_spi;
display_frm_u disp_frm_buf;
uint8_t disp_pixel[DISP_ROWS] = {0b10000001,
								 0b01000010,
								 0b00100100,
								 0b00011000,
								 0b00011000,
								 0b00100100,
								 0b01000010,
								 0b10000001};

void disp_send_cmd(uint8_t cmd, uint8_t val);
void disp_draw_bitmap_task(void);
void disp_set_bitmap(const uint8_t* const bitmap);

void disp_or_tables(uint8_t* tab_dest, uint8_t* tab_mask);

void disp_set_note(notes_t letter)
{
	const uint8_t* char_tab_ptr;

	switch(letter)
	{
		case C2:
		case C3:
		case C4:
			char_tab_ptr = c_bitmap;
			break;
		case CIS2:
		case CIS3:
		case CIS4:
			char_tab_ptr = cis_bitmap;
			break;
		case D2:
		case D3:
		case D4:
			char_tab_ptr = d_bitmap;
			break;
		case DIS2:
		case DIS3:
		case DIS4:
			char_tab_ptr = dis_bitmap;
			break;
		case E2:
		case E3:
		case E4:
			char_tab_ptr = e_bitmap;
			break;
		case F2:
		case F3:
		case F4:
			char_tab_ptr = f_bitmap;
			break;
		case FIS2:
		case FIS3:
			char_tab_ptr = fis_bitmap;
			break;
		case G2:
		case G3:
			char_tab_ptr = g_bitmap;
			break;
		case GIS2:
		case GIS3:
			char_tab_ptr = gis_bitmap;
			break;
		case A2:
		case A3:
			char_tab_ptr = a_bitmap;
			break;
		case AIS2:
		case AIS3:
			char_tab_ptr = ais_bitmap;
			break;
		case B2:
		case B3:
			char_tab_ptr = h_bitmap;
			break;
		case BAD_NOTE:
		default:
//			char_tab_ptr = question_bitmap;
			char_tab_ptr = space_bitmap;
			break;
	}

	disp_set_bitmap(char_tab_ptr);
}

void disp_or_tables(uint8_t* tab_dest, uint8_t* tab_mask)
{
	for(uint8_t row_cnt = 0u; row_cnt < DISP_ROWS; row_cnt++)
	{
		tab_dest[row_cnt] |= tab_mask[row_cnt];
	}
}


void disp_set_similarity_level(int8_t similarity_level)
{

	if(similarity_level >= 0)
	{
		if((similarity_level >= 10) && (similarity_level <= 30))
		{
			disp_or_tables(disp_pixel, plus1_bitmap);
		}
		else if((similarity_level >= 30) && (similarity_level <= 50))
		{
			disp_or_tables(disp_pixel, plus2_bitmap);
		}
		else if((similarity_level >= 50) && (similarity_level <= 70))
		{
			disp_or_tables(disp_pixel, plus3_bitmap);
		}
		else if((similarity_level >= 70) && (similarity_level <= 100))
		{
			disp_or_tables(disp_pixel, plus4_bitmap);
		}
		else
		{
			disp_or_tables(disp_pixel, underscore_bitmap);
		}
	}
	else
	{
		if((similarity_level <= -10) && (similarity_level >= -30))
		{
			disp_or_tables(disp_pixel, minus1_bitmap);
		}
		else if((similarity_level <= -30) && (similarity_level >= -50))
		{
			disp_or_tables(disp_pixel, minus2_bitmap);
		}
		else if((similarity_level <= -50) && (similarity_level >= -70))
		{
			disp_or_tables(disp_pixel, minus3_bitmap);
		}
		else if((similarity_level <= -70) && (similarity_level >= -100))
		{
			disp_or_tables(disp_pixel, minus4_bitmap);
		}
		else
		{
			disp_or_tables(disp_pixel, underscore_bitmap);
		}
	}
}

void disp_set_bitmap(const uint8_t* const bitmap)
{
	memcpy(disp_pixel, bitmap, sizeof(disp_pixel));
}

void disp_draw_bitmap_task(void)
{
	static uint8_t row_cnt = 0u;

	disp_send_cmd(row_cnt + MAX7219_DIGIT0_REGISTER, disp_pixel[row_cnt]);

	row_cnt++;
	row_cnt %= DISP_ROWS;
}

void display_task(void)
{
	disp_draw_bitmap_task();
}

void disp_init(SPI_HandleTypeDef* hspi)
{
  disp_spi = hspi;

  HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_SET);

  HAL_Delay(1);
  /*Dummy byte*/
  disp_send_cmd(MAX7219_NOOP_REGISTER, 0x00);
  HAL_Delay(1);
  /* Decode mode: no decode */
  disp_send_cmd(MAX7219_DECODE_MODE_REGISTER, NoDecode);
  HAL_Delay(1);
  /* Set Intensity */
  disp_send_cmd(MAX7219_INTENSITY_REGISTER, 1);
  HAL_Delay(1);
  /* Set scan Limit */
  disp_send_cmd(MAX7219_SCAN_LIMIT_REGISTER, ScanDigit0_7);
  HAL_Delay(1);
  /* Turn off test mode */
  disp_send_cmd(MAX7219_DISPLAY_TEST_REGISTER, TestOff);
  HAL_Delay(1);
  /* Normal Operation mode*/
  disp_send_cmd(MAX7219_SHUTDOWN_REGISTER, NormalOperation);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT0_REGISTER, 0b00000001);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT1_REGISTER, 0b00000010);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT2_REGISTER, 0b00000100);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT3_REGISTER, 0b00001000);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT4_REGISTER, 0b00010000);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT5_REGISTER, 0b00100000);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT6_REGISTER, 0b01000000);
  HAL_Delay(1);
  disp_send_cmd(MAX7219_DIGIT7_REGISTER, 0b10000000);
  HAL_Delay(1);
}

void disp_send_cmd(uint8_t cmd, uint8_t val)
{
	disp_frm_buf.addr = cmd;
	disp_frm_buf.val = val;

	/* CS Pin LOW level*/
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit_IT(disp_spi, &disp_frm_buf, 1u);
}
