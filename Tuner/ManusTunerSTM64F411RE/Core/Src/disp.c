
#include <stdint.h>
#include "main.h"
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

void disp_set_char(char letter)
{
	const uint8_t* char_tab_ptr;

	switch(letter)
	{
		case 'e':
			char_tab_ptr = e_bitmap;
			break;
		case 'a':
			char_tab_ptr = a_bitmap;
			break;
		case 'd':
			char_tab_ptr = d_bitmap;
			break;
		case 'g':
			char_tab_ptr = g_bitmap;
			break;
		case 'h':
			char_tab_ptr = h_bitmap;
			break;
		case 'c':
			char_tab_ptr = c_bitmap;
			break;
		case 'f':
			char_tab_ptr = f_bitmap;
			break;
		case ' ':
			char_tab_ptr = space_bitmap;
			break;
		default:
			char_tab_ptr = question_bitmap;
			break;
	}

	disp_set_bitmap(char_tab_ptr);
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
