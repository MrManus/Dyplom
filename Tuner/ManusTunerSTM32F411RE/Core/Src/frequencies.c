#include "main.h"
#include <stdint.h>
#include <float.h>
#include "frequencies.h"
#include "disp.h"

const float notes_freqs[NOTES_NUMBER][2u] = {
		[C2]		= {63.58f, 67.36f},
		[CIS2]		= {67.36f, 71.36f},
		[D2]		= {71.36f, 75.60f},
		[DIS2]		= {75.60f, 80.10f},
		[E2]		= {80.10f, 84.96f},
		[F2]		= {84.86f, 89.91f},
		[FIS2]		= {89.91f, 95.25f},
		[G2]		= {95.25f, 100.92f},
		[GIS2]		= {100.92f, 106.91f},
		[A2]		= {106.91f, 113.27f},
		[AIS2]		= {113.27f, 120.01f},
		[B2]		= {120.10f, 127.14f},
		[C3]		= {127.14f, 134.70f},
		[CIS3]		= {134.70f, 142.71f},
		[D3]		= {142.71f, 151.20f},
		[DIS3]		= {151.20f, 160.19f},
		[E3]		= {160.19f, 169.71f},
		[F3]		= {169.71f, 179.81f},
		[FIS3]		= {179.81f, 190.50f},
		[G3]		= {190.50f, 201.83f},
		[GIS3]		= {201.83f, 213.83f},
		[A3]		= {213.83f, 225.54f},
		[AIS3]		= {226.54f, 240.01f},
		[B3]		= {240.01f, 254.29f},
		[C4]		= {254.29f, 269.41f},
		[CIS4]		= {269.41f, 285.42f},
		[D4]		= {285.42f, 302.40f},
		[DIS4]		= {302.40f, 320.38f},
		[E4]		= {320.38f, 339.43f},
		[F4]		= {339.43f, 359.61f}};

notes_t FindNote(float FrequencyHz)
{
	notes_t note = BAD_NOTE;

	for(uint8_t notes_cnt = 0u; notes_cnt < NOTES_NUMBER; notes_cnt++)
	{
		if((FrequencyHz > notes_freqs[notes_cnt][NOTE_LOWER_FREQ]) &&
		   (FrequencyHz < notes_freqs[notes_cnt][NOTE_UPPER_FREQ])	)
		{
			note = notes_cnt;
			break;
		}
	}

	return note;
}

int8_t CalcSimiliratyLevel(notes_t note, float FrequencyHz)
{
	float freq_range = (notes_freqs[note][NOTE_UPPER_FREQ] - notes_freqs[note][NOTE_LOWER_FREQ])/2.0f;
	float middle_freq = (notes_freqs[note][NOTE_UPPER_FREQ] + notes_freqs[note][NOTE_LOWER_FREQ])/2.0f;
	float freq_diff = FrequencyHz - middle_freq;

	int8_t freq_percent = (int8_t)((freq_diff/freq_range) * 100);

	return freq_percent;
}
