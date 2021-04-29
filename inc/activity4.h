/**
 * @file activity4.h
 * @author Khubi Thakkar
 * @brief Header file for activity 4
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED

#include <avr/io.h>
#include <util/delay.h>


void USARTInit(uint16_t);
char USARTReadChar();
void USARTWriteChar(char);
void part3(void);


#endif
