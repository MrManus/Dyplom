/*
 * frequency_calculator.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */

#ifndef INC_DISP_CHARS_H_
#define INC_DISP_CHARS_H_

const uint8_t e_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00111100,
									 0b00100000,
									 0b00111100,
									 0b00100000,
									 0b00111100,
									 0b00000000};

const uint8_t a_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00011000,
									 0b00100100,
									 0b00111100,
									 0b00100100,
									 0b00100100,
									 0b00000000};

const uint8_t d_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00111000,
									 0b00100100,
									 0b00100100,
									 0b00100100,
									 0b00111000,
									 0b00000000};

const uint8_t g_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00011100,
									 0b00100000,
									 0b00101100,
									 0b00100100,
									 0b00011100,
									 0b00000000};

const uint8_t h_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00100100,
									 0b00100100,
									 0b00111100,
									 0b00100100,
									 0b00100100,
									 0b00000000};

const uint8_t c_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00011100,
									 0b00100000,
									 0b00100000,
									 0b00100000,
									 0b00011100,
									 0b00000000};

const uint8_t f_bitmap[DISP_ROWS] = {0b00000000,
									 0b00000000,
									 0b00111100,
									 0b00100000,
									 0b00111100,
									 0b00100000,
									 0b00100000,
									 0b00000000};

const uint8_t space_bitmap[DISP_ROWS] = {	0b00000000,
											0b00000000,
											0b00000000,
											0b00000000,
											0b00000000,
											0b00000000,
											0b00000000,
											0b00000000};

const uint8_t question_bitmap[DISP_ROWS] = {	0b00000000,
												0b00111000,
												0b00000100,
												0b00011100,
												0b00100000,
												0b00011000,
												0b00000000,
												0b00001100};

#endif
