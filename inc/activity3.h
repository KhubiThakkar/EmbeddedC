/**
 * @file activity3.h
 * @author Khubi Thakkar
 * @brief header for Activity 3
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __ACTIVITY3_H__
#define __ACTIVITY3_H__

#include <avr/io.h>
#include <util/delay.h>

void init_PWM(void);
void init_PWMpin(void);
void compare(void);

#endif
