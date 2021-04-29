#include <avr/io.h>
#include <util/delay.h>

void init_ADC()
{   ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);

}

uint16_t ReadADC(uint8_t ch)
{
    //select adc channel
    ADMUX &= 0xf8;
    ch=ch&0b00000111;
    ADMUX |= ch;
    //Start conversion
    ADCSRA |= (1<<ADSC);
    //wait for conversion
    while(!(ADCSRA & (1<<ADIF)));
    ADCSRA |= (1<<ADIF);
    return (ADC);

}

void init_port()
{
     DDRD &= ~(1<<PD0);     //Make PORTD0 as input pin
     DDRC &= ~(1<<PC0);     // Make PORTC0 as input pin
     DDRD |= (1<<PD6);      // set PD6 for output
     DDRB |= (1<<PB1);      //Make PORTB1 as output pin
}


int main(void)
{
    TCCR0A |= (1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
    // Fast PWM - Non inverting mode of pin PD6
    TCCR0B |= (1<<CS00);
    // no prescaler

    init_port();
    init_ADC();
   //uint16_t temp;
    PORTB = 0x00;
    while(1)
    {
        if( (PIND & (1<<PD0)) == 1 )
            {
                PORTB |= (1<<PB1);
                ReadADC(0);

                // changing the duty cycle of waveform
                if (ADC>0 && ADC<200){
                    OCR0A = 51;
                }
                else if(ADC > 210 && ADC < 500){
                    OCR0A = 101;
                }
                else if(ADC > 510 && ADC < 700){
                    OCR0A = 178;
                }
                else if (ADC > 710 && ADC < 1024){
                    OCR0A = 242;
                }


                _delay_ms(200);
            }

        else
            ADCH=0x00;
            ADCL=0x00;
    }

    return 0;
}
