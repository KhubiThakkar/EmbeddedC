/**
 * @file activity4.c
 * @author Khubi Thakkar
 * @brief Activity 4: Communication of data using USART
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
 * @brief initialization of USART
 * 
 * @param ubrr_value 
 */
void USARTInit(uint16_t ubrr_value)
{
    UBRR0H = (ubrr_value>>8) & 0x00ff;
    UBRR0L = ubrr_value;
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

/**
 * @brief Reading character recieved by USART
 * 
 * @return char 
 */
char USARTReadChar()
{
    while(!(UCSR0A & (1<<RXC0)))
    {
      //do nothing
    }
    return UDR0;
}

/**
 * @brief Sending data by USART
 * 
 * @param data 
 */
void USARTWriteChar(char data)
{
    while(!(UCSR0A & (1<<UDRE0)))
    {
        //do nothing
    }
    UDR0 = data;
}


/**
 * @brief after reading the duty cycle value of PWM the temperature is decided and sent through USART
 * 
 */
void part3 (void)
{
    USARTInit(103);
    if(OCR0A == 50)
    {
        USARTWriteChar(20);
    }
    else if(OCR0A == 101)
    {
        USARTWriteChar(25);
    }
    else if(OCR0A == 178)
    {
        USARTWriteChar(29);
    }
    else if(OCR0A == 242)
    {
        USARTWriteChar(33);
    }
}
