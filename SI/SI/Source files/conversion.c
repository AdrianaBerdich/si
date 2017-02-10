/*
 * conversion.c
 *
 * Created: 5/9/2016 6:43:57 PM
 *  Author: User
 */ 
#include "aes/aes.h"
#include "adc.h"
#include "serial.h"
#include "encrypt.h"
#include "serial.h"

char hexa_to_ascii(uint8_t input)
{

	input &= 0x0F;

	if (input < 10)
	{
		input = input + '0';
	}
	else
	{
		input = input + 'A' - 10;
	}

	return (char)input;
}

void print_hex(uint8_t *ptr, uint8_t size)
{
	uint8_t i;

	for(i=0; i<size; i++)     {
		USART_Transmit(hexa_to_ascii(ptr[i]>>4));
		USART_Transmit(hexa_to_ascii(ptr[i]&0x0F));
	}
}