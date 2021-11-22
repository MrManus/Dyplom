/*
 * frequency_calculator.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */
#include "main.h"
#include "frequency_calculator.h"
#include "math.h"


float GetCrossCorr(int16_t *SignalBuffer, uint16_t SignalLength, int32_t *CrossCorrBuffer)
{

	uint16_t LagAmount = ((2*SignalLength)-1);
	uint16_t SamplesAmount;
	int32_t Nominator = 0;
	uint16_t StarterSample;

	uint16_t MiddleLag = SignalLength;
	uint16_t MiddlePeakHalfLength;
	int32_t SecHighPeakValue = 0;
	uint16_t SecHighPeakPos;

	uint32_t SamplingFrequency = SAMPLING_FREQUENCY;
	uint16_t Period = 0;
	float PeriodHz = 0;

	for(uint16_t i = 0; i<LagAmount; i++)
	{
		if(i < MiddleLag)
		{
			SamplesAmount = i + 1;
			Nominator = 0;
			StarterSample = SignalLength - SamplesAmount;

			for(uint16_t j = 0; j < SamplesAmount; j++)
			{

				Nominator = Nominator + ((int32_t)SignalBuffer[j] * (int32_t)SignalBuffer[StarterSample + j]);
			}
			CrossCorrBuffer[i] = Nominator;
		}
		else
		{
			SamplesAmount = (SignalLength - (i % MiddleLag)) - 1;
			Nominator = 0;
			StarterSample = SignalLength - SamplesAmount;

			for(uint16_t j = 0; j < SamplesAmount; j++)
			{
				Nominator = Nominator + ((int32_t)SignalBuffer[StarterSample + j] * (int32_t)SignalBuffer[j]);
			}
			CrossCorrBuffer[i] = Nominator;
		}
	}

	for(uint16_t LagCounter = 0; LagCounter < LagAmount; LagCounter++)
	{
		if(CrossCorrBuffer[LagCounter] < 0)
		{
			CrossCorrBuffer[LagCounter] = 0;
		}
	}

	for(uint16_t LagCounter = MiddleLag; LagCounter < LagAmount; LagCounter++)
	{
		if(CrossCorrBuffer[LagCounter] == 0)
		{
			MiddlePeakHalfLength = (LagCounter - 1) - MiddleLag;
			break;
		}
	}

	for(uint16_t LagCounter = (MiddleLag - MiddlePeakHalfLength); LagCounter < (MiddleLag + MiddlePeakHalfLength); LagCounter++)
	{
		CrossCorrBuffer[LagCounter] = 0;
	}

	for(uint16_t LagCounter = 0; LagCounter < LagAmount; LagCounter++)
	{
		if(CrossCorrBuffer[LagCounter] > SecHighPeakValue)
		{
			SecHighPeakValue = CrossCorrBuffer[LagCounter];
			SecHighPeakPos = LagCounter;
		}
	}

	if(SecHighPeakPos < MiddleLag)
	{
		Period = MiddleLag - SecHighPeakPos;
	}
	else if (SecHighPeakPos > MiddleLag)
	{
		Period = SecHighPeakPos - MiddleLag;
	}

	return PeriodHz = (float)SamplingFrequency / (float)Period;

}

