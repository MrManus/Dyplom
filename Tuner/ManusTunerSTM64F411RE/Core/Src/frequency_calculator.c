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

	uint16_t LagAmount = SignalLength/2;
	uint16_t SamplesAmount;
	int32_t Nominator = 0;
	uint16_t StarterSample;

	uint16_t MiddleLag = 0;
	uint16_t MiddlePeakHalfLength;
	int32_t SecHighPeakValue = 0;
	uint16_t SecHighPeakPos;

	uint32_t SamplingFrequency = SAMPLING_FREQUENCY;
	uint16_t Period = 0;
	float PeriodHz = 0;

	for(uint16_t i = 0; i<LagAmount; i++)
	{

			SamplesAmount = (SignalLength - i);
			Nominator = 0;
			StarterSample = SignalLength - SamplesAmount;

			for(uint16_t j = 0; j < SamplesAmount; j++)
			{
				Nominator = Nominator + ((int32_t)SignalBuffer[StarterSample + j] * (int32_t)SignalBuffer[j]);
			}
			if(Nominator < 0)
			{
				Nominator = 0;
			}
			CrossCorrBuffer[i] = Nominator;

	}

// Calculating the length of middle corr peak
	for(uint16_t LagCounter = MiddleLag; LagCounter < LagAmount; LagCounter++)
	{
		if(CrossCorrBuffer[LagCounter] == 0)
		{
			MiddlePeakHalfLength = (LagCounter - 1);
			break;
		}
		else
		{
			CrossCorrBuffer[LagCounter] = 0;
		}
	}

// Setting middle peak to zeros
//	for(uint16_t LagCounter = MiddleLag; LagCounter < MiddlePeakHalfLength; LagCounter++)
//
//	{
//		CrossCorrBuffer[LagCounter] = 0;
//	}

// Finding second highest peak in corr
	for(uint16_t LagCounter = 0; LagCounter < LagAmount; LagCounter++)
	{
		if(CrossCorrBuffer[LagCounter] > SecHighPeakValue)
		{
			SecHighPeakValue = CrossCorrBuffer[LagCounter];
			SecHighPeakPos = LagCounter;
		}
	}


	Period = SecHighPeakPos;

	return PeriodHz = (float)SamplingFrequency / (float)Period;

}

