/*
 * parser_simple.h
 *
 *  Created on: Mar 1, 2022
 *      Author: Manus
 */

#ifndef INC_PARSER_SIMPLE_H_
#define INC_PARSER_SIMPLE_H_

#define ENDLINE '\n'

void Parser_TakeLine(RingBuffer_t *Buf, uint8_t *Destination);

void Parser_Parse (uint8_t *DataToParse);

#endif /* INC_PARSER_SIMPLE_H_ */
