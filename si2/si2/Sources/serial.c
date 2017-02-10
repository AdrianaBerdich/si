/*
 * serial.c
 *
 * Created: 4/27/2016 9:56:48 PM
 *  Author: User
 */ 
/*
 * CFile1.c
 *
 * Created: 3/20/2016 6:11:53 PM
 *  Author: User
 */ 
#include <avr/io.h>
#include "serial.h"

// function to initialize UART
void USART_Init( unsigned int BAUDRATE)
{
	UBRR0H = (BAUDRATE>>8);                      // shift the register right by 8 bits
	UBRR0L = BAUDRATE;                           // set baud rate
	UCSR0B|= (1<<TXEN0)|(1<<RXEN0);                // enable receiver and transmitter
	UCSR0B |= (1<<RXCIE0);                         //Enable ISR
	/* Set frame format: 8data, 2stop bit */
	UCSR0C|= (1<<USBS0)|(3<<UCSZ00);  // 8bit data format UPM00 parity register, UCSZ00 Character SiZem USBS0 stop bite
}

void USART_Transmit( unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data*/
	UDR0 = data;
}

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) )
	;
	/* Get and return received data from buffer*/
	return UDR0;
}

void UsartWrite(unsigned char *data, unsigned char len)
{
	unsigned char i = 0;
	int length = 50;
	while (length > 0)
	{
		// Wait for buffers to be free
		if (UCSR0A & (1<<UDRE0))
		{
			UDR0 = data[i++]; // UDR0 = USART I/O Data Register
			length--;
		}
	}
	 // Wait for transmission to be ready
	 while (!(UCSR0A & (1<<TXC0)));
	 
	 // Wait a few cycles before exiting function
	 for (i = 0; i < 0xFE; i++)
	 {
		 
		 for(length = 0; length < 0xFE; length++);
	 }
}