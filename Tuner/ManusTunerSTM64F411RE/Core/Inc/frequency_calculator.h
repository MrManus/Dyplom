/*
 * frequency_calculator.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */

#ifndef INC_FREQUENCY_CALCULATOR_H_
#define INC_FREQUENCY_CALCULATOR_H_

#define SAMPLING_FREQUENCY 192000;
//#define SAMPLING_FREQUENCY 500;

float GetCrossCorr(uint16_t *SignalBuffer, uint16_t SignalLength, float *CrossCorrBuffer);

//float LeftCrossCorr(float *SignalBuffer, uint16_t SignalLength, uint16_t SamplesAmount);

#endif /* INC_FREQUENCY_CALCULATOR_H_ */
