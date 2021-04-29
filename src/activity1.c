#include "activity1.h"

void part1(void){
    init_gpiopins();
    // IF BOTH SWITCHES ARE ON
    if(((PIND & (1<<PD0)) && (PIND & (1<<PD1))) == 1){
        PORTB |= (1<<PB1);      // SET PIN PB1
    }
    else{
        PORTB &= ~(1<<PB1);     // CLEAR PIN PB1
    }
}