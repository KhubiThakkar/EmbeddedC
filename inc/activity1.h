#ifndef __ACTIVITY1_H__
#define __ACTIVITY1_H__

#include <avr/io.h>

/**
 * @brief It will initialize the GPIO pins for heater and seat as inputs and 
 *  the indicator LED pin as output
 */
void init_gpiopins(void){
    DDRD &= ~(1<<PD0);  // input switch
    DDRD &= ~(1<<PD1);  // input switch
    DDRB |= (1<<PB1);   // output switch
}
void part1(void);

#endif