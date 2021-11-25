/*
 * frequency_calculator.h
 *
 *  Created on: Nov 8, 2021
 *      Author: Manus
 */

#ifndef INC_DISP_H_
#define INC_DISP_H_

#define DISP_ROWS	8u
#define DISP_COLS	8u

void disp_init(SPI_HandleTypeDef* hspi);
void display_task(void);
void disp_set_char(char letter);

#endif

