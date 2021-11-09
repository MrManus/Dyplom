/*
 * frequency_calculator.c
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */
#include "main.h"
#include "frequency_calculator.h"
#include "math.h"


void GetCrossCorr(float *SignalBuffer, uint16_t SignalLength, float *CrossCorrBuffer)
{
	uint16_t LagAmount = ((2*SignalLength)-1);
	uint16_t SamplesAmount;
	uint16_t MiddleLag = SignalLength;


	for(uint16_t i = 0; i<LagAmount; i++)
	{
		if(i < MiddleLag)
		{
			SamplesAmount = i + 1;
			float Nominator = 0;
			uint16_t StarterSample = SignalLength - SamplesAmount;

			for(uint16_t j = 0; j < SamplesAmount; j++)
				{
					Nominator = Nominator + (SignalBuffer[j] * SignalBuffer[StarterSample + j]);
				}
			CrossCorrBuffer[i] = Nominator;
		}
		else
		{
			SamplesAmount = (SignalLength - (i % MiddleLag)) - 1;
			float Nominator = 0;
			uint16_t StarterSample = SignalLength - SamplesAmount;

			for(uint16_t j = 0; j < SamplesAmount; j++)
				{
					Nominator = Nominator + ( SignalBuffer[StarterSample + j] * SignalBuffer[j]);
				}
			CrossCorrBuffer[i] = Nominator;
		}
	}
}

//float LeftCrossCorr(float *SignalBuffer, uint16_t SignalLength, uint16_t SamplesAmount)
//{
//	float CorrNorm = 0;
//	uint16_t StarterSample = SignalLength - SamplesAmount;
//	float Nominator = 0;
////	float Denominator = 0;
////	float Xsquared = 0;
////	float Ysquared = 0;
//
//
//	for(uint16_t i = 0; i < SamplesAmount; i++)
//	{
//		Nominator = Nominator + (SignalBuffer[i] * SignalBuffer[StarterSample + i]);
////		Xsquared = Xsquared + (SignalBuffer[i] * SignalBuffer[i]);
////		Ysquared = Ysquared + (SignalBuffer[StarterSample + i] * SignalBuffer[StarterSample + i]);
//	}
////	Denominator = sqrt(Xsquared + Ysquared);
////	CorrNorm = (Nominator / Denominator);
//	CorrNorm = Nominator;
//	return CorrNorm;
//}
