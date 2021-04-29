/**
 * @file activity1.c
 * @author KHUBI THAKKAR 
 * @brief ACTIVITY 1: RELATED TO INTERFACING GPOI PINS FOR INPUTS AND OUTPUTS
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"


/**
 * @brief It will initialize the GPIO pins for heater and seat as inputs and
 *  the indicator LED pin as output
 */
void init_gpiopins(void){
    DDRD &= ~(1<<PD0);  // input switch
    DDRD &= ~(1<<PD1);  // input switch
    DDRB |= (1<<PB1);   // output switch
}


/**
 * @brief We check if the both the switches are ON, LED is turned ON
 * In any other case, LED is turned OFF
 * 
 */
void part1(void){
    // IF BOTH SWITCHES ARE ON
    if(((PIND & (1<<PD0)) && (PIND & (1<<PD1))) == 1){
        PORTB |= (1<<PB1);  // LED SET
    }
    else{
        PORTB &= ~(1<<PB1); // LED CLEAR
    }
}
