/*
 * frequency_calculator.c
 *
 *  Created on: Nov 6, 2021
 *      Author: Manus
 */
#include "main.h"
#include "frequency_calculator.h"

//, uint8_t *SignalLength
void GetCrossCorr(uint16_t *SignalBuffer, uint8_t *CrossCorrBuffer)
{

	for(uint8_t i = 0; i<5; i++)
	{
		CrossCorrBuffer[i] = SignalBuffer[3];
	}
}
