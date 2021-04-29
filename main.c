/**
 * @file main.c
 * @author Khubi Thakkar (you@domain.com)
 * @brief
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
 * @brief The main function integrating all the activities
 *
 * @return int
 */
int main(void){
    init_gpiopins();
    while(1){

        part1();    // Activity 1: GPIO interfacing
        part2();    // Activity 2 and 3: ADC and PWM interfacing
        part3();    // Activity 4: USART interfacing
        
    }
    return 0;
}

