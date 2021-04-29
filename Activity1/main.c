/*
 */
#include <avr/io.h>

int main(void)
{

    // Insert code
    DDRB &= ~(1<<PB0);  // input switch
    DDRB &= ~(1<<PB1);  // input switch
    DDRC |= (1<<PC0);   // output switch
    while(1){
        if(((PINB & (1<<PB0)) && (PINB & (1<<PB1))) == 1){
            PORTC |= (1<<PC0);
        }
        else{
            PORTC &= ~(1<<PC0);
        }
    }

    return 0;
}
