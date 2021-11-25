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



	uint16_t LagAmount = SignalLength;
	uint16_t SamplesAmount;
	int32_t Nominator = 0;
	uint16_t StarterSample;

	uint16_t MiddleLag = 0;
//	uint16_t MiddlePeakHalfLength;
	int32_t SecHighPeakValue = 0;
	uint16_t SecHighPeakPos;
//New
	int32_t ThinSecHighPeakValue = 0;
	uint16_t ThinSecHighPeakPos ;
	uint16_t AimedPeakPos;


	uint32_t SamplingFrequency = SAMPLING_FREQUENCY;
	uint16_t Period = 0;
	float PeriodHz = 0;

	uint16_t ThiningFactor = 20;
	uint16_t SearchRange = 100;
	uint16_t ThinLagAmount = LagAmount/ThiningFactor;

	uint32_t ThinCrossCorrBuffer[ThinLagAmount];

	uint16_t ThinCorrIndex = 0;
	uint16_t AimedCorrIndex = 0;

	for(uint16_t i = 0; i<LagAmount; i++)
	{
		if(i%ThiningFactor == 0)
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
			ThinCrossCorrBuffer[ThinCorrIndex] = Nominator;
			ThinCorrIndex++;
		}
	}


// Calculating the length of middle corr peak
	for(uint16_t LagCounter = MiddleLag; LagCounter < ThinLagAmount; LagCounter++)
	{
		if(ThinCrossCorrBuffer[LagCounter] == 0)
		{
//			MiddlePeakHalfLength = (LagCounter - 1);
			break;
		}
		else
		{
			ThinCrossCorrBuffer[LagCounter] = 0;
		}
	}



// Finding second highest peak in corr
	for(uint16_t LagCounter = 0; LagCounter < ThinLagAmount; LagCounter++)
	{
		if(ThinCrossCorrBuffer[LagCounter] > ThinSecHighPeakValue)
		{
			ThinSecHighPeakValue = ThinCrossCorrBuffer[LagCounter];
			ThinSecHighPeakPos = LagCounter;
		}
	}

// New Corr
	AimedPeakPos = ThinSecHighPeakPos * ThiningFactor;
	//39
	for(uint16_t i = (AimedPeakPos - SearchRange); i<=(AimedPeakPos + SearchRange); i++)
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
			CrossCorrBuffer[AimedCorrIndex] = Nominator;
			AimedCorrIndex++;

	}

	for(uint16_t LagCounter = 0; LagCounter <= (SearchRange*2); LagCounter++)
	{
		if(CrossCorrBuffer[LagCounter] > SecHighPeakValue)
		{
			SecHighPeakValue = CrossCorrBuffer[LagCounter];
			SecHighPeakPos = (AimedPeakPos - SearchRange) + LagCounter;
		}
	}


	Period = SecHighPeakPos;

	return PeriodHz = (float)SamplingFrequency / (float)Period;

}

