/*
 * frequency_calculator.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */

#ifndef INC_FREQUENCIES_H_
#define INC_FREQUENCIES_H_

#define NOTE_LOWER_FREQ	0u
#define NOTE_UPPER_FREQ 1u

typedef enum
{
	BAD_NOTE = 0u,
	C2,
	CIS2,
	D2,
	DIS2,
	E2,
	F2,
	FIS2,
	G2,
	GIS2,
	A2,
	AIS2,
	B2,
	C3,
	CIS3,
	D3,
	DIS3,
	E3,
	F3,
	FIS3,
	G3,
	GIS3,
	A3,
	AIS3,
	B3,
	C4,
	CIS4,
	D4,
	DIS4,
	E4,
	F4,
	NOTES_NUMBER
}notes_t;

extern const float notes_freqs[NOTES_NUMBER][2u];

notes_t FindNote(float FrequencyHz);

#endif
