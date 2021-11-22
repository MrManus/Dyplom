/*
 * frequency_calculator.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */
#include "main.h"
#include "frequency_calculator.h"
#include "math.h"


float GetCrossCorr(int16_t *SignalBuffer, uint16_t SignalLength, float *CrossCorrBuffer)
{

	uint16_t LagAmount = ((2*SignalLength)-1);
	uint16_t SamplesAmount;
	float Nominator = 0;
	uint16_t StarterSample;

	uint16_t MiddleLag = SignalLength;
	uint16_t MiddlePeakHalfLength;
	float SecHighPeakValue = 0;
	uint16_t SecHighPeakPos;

	float SamplingFrequency = SAMPLING_FREQUENCY;
	float Period = 0;
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

				Nominator = Nominator + ((float)SignalBuffer[j] * (float)SignalBuffer[StarterSample + j]);
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
				Nominator = Nominator + ((float)SignalBuffer[StarterSample + j] * (float)SignalBuffer[j]);
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

	return PeriodHz = SamplingFrequency / Period;

}

