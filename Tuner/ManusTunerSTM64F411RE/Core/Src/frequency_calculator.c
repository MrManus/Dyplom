/*
 * frequency_calculator.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */
#include "main.h"
#include "math.h"
#include "adc.h"
#include "frequency_calculator.h"

#define CrossCorelationLength (SINGLE_CONV_SAMPLES/2)

#define THINING_FACTOR 		20u
#define SEARCH_RANGE 		20u
#define LAG_AMOUNT 			(SINGLE_CONV_SAMPLES/2)
#define THIN_LAG_AMOUNT 	(LAG_AMOUNT/THINING_FACTOR)
#define MIDDLE_LAG			0u

static int32_t AimedCrossCorr[CrossCorelationLength];
static int32_t ThinCrossCorrBuffer[THIN_LAG_AMOUNT];

static float GetCrossCorr(int16_t *SignalBuffer);

static float GetCrossCorr(int16_t *SignalBuffer)
{
	uint16_t SamplesAmount;
	int32_t Nominator = 0;
	uint16_t StarterSample;

	int32_t SecHighPeakValue = 0;
	uint16_t SecHighPeakPos;

	int32_t ThinSecHighPeakValue = 0;
	uint16_t ThinSecHighPeakPos ;
	uint16_t AimedPeakPos;

	uint16_t Period = 0;

	uint16_t ThinCorrIndex = 0;
	uint16_t AimedCorrIndex = 0;

	for(uint16_t i = 0; i<LAG_AMOUNT; i++)
	{
		if(i%THINING_FACTOR == 0)
		{
			SamplesAmount = (SINGLE_CONV_SAMPLES - i);
			Nominator = 0;
			StarterSample = SINGLE_CONV_SAMPLES - SamplesAmount;

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
	for(uint16_t LagCounter = MIDDLE_LAG; LagCounter < THIN_LAG_AMOUNT; LagCounter++)
	{
		if(ThinCrossCorrBuffer[LagCounter] == 0)
		{
			break;
		}
		else
		{
			ThinCrossCorrBuffer[LagCounter] = 0;
		}
	}



// Finding second highest peak in corr
	for(uint16_t LagCounter = 0; LagCounter < THIN_LAG_AMOUNT; LagCounter++)
	{
		if(ThinCrossCorrBuffer[LagCounter] > ThinSecHighPeakValue)
		{
			ThinSecHighPeakValue = ThinCrossCorrBuffer[LagCounter];
			ThinSecHighPeakPos = LagCounter;
		}
	}

// New Corr
	AimedPeakPos = ThinSecHighPeakPos * THINING_FACTOR;
	//39
	for(uint16_t i = (AimedPeakPos - SEARCH_RANGE); i<=(AimedPeakPos + SEARCH_RANGE); i++)
	{
			SamplesAmount = (SINGLE_CONV_SAMPLES - i);
			Nominator = 0;
			StarterSample = SINGLE_CONV_SAMPLES - SamplesAmount;

			for(uint16_t j = 0; j < SamplesAmount; j++)
			{
				Nominator = Nominator + ((int32_t)SignalBuffer[StarterSample + j] * (int32_t)SignalBuffer[j]);
			}
			if(Nominator < 0)
			{
				Nominator = 0;
			}
			AimedCrossCorr[AimedCorrIndex] = Nominator;
			AimedCorrIndex++;

	}

	for(uint16_t LagCounter = 0; LagCounter <= (SEARCH_RANGE*2); LagCounter++)
	{
		if(AimedCrossCorr[LagCounter] > SecHighPeakValue)
		{
			SecHighPeakValue = AimedCrossCorr[LagCounter];
			SecHighPeakPos = (AimedPeakPos - SEARCH_RANGE) + LagCounter;
		}
	}


	Period = SecHighPeakPos;

	return (float)SAMPLING_FREQUENCY / (float)Period;
}

float CalcXcorrFreq(int16_t *SignalBuffer)
{
	return GetCrossCorr(SignalBuffer);
}

