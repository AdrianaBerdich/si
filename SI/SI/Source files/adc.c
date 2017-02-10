/*
 * adc.c
 *
 * Created: 5/1/2016 10:59:28 PM
 *  Author: User
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "adc.h"


void InitADC()
{
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); //prescaler selection 128
}

uint16_t ReadADC(uint8_t ch)
{
	ch &= 0b00000111;
	ADMUX |= ch;//= (ADMUX & 0xF8) | ch;
	
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADIF));
	ADCSRA|=(1<<ADIF);
	
	int val = ADC;
	ADCH = 0;
	ADCL = 0;
	return (val);
}