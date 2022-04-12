/*
 * utils.c
 *
 *  Created on: Mar 1, 2022
 *      Author: Manus
 */
#include "main.h"
#include "utils.h"
#include "usart.h"
#include "string.h"

void UartLog(char* Message)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)Message, strlen(Message), 1000);
}
