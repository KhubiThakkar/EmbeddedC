//#include <avr/io.h>
//#include <util/delay.h>
//
//void waveform(){
//    TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
//    // Fast PWM - Non inverting mode of pin PD6
//
//    TCCR0B |= (1<<CS00);
//    // no prescaler
//
//    DDRD |= (1<<PD6);
//    // set PD6 for output
//
//    OCR0A = 51;
//    while(1){
//
//    }
//
//}
