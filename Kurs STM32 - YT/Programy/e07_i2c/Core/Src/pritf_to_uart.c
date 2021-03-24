/*
 * pritf_to_uart.c
 *
 *  Created on: Mar 22, 2021
 *      Author: Manus
 */

#include "usart.h"

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 1000);
	return ch;
}
