/*
 * serial.h
 *
 * Created: 4/27/2016 10:15:28 PM
 *  Author: User
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_



extern void USART_Init( unsigned int BAUDRATE);
extern void USART_Transmit( unsigned char data );
extern unsigned char USART_Receive( void );
extern void UsartWrite(unsigned char *data, unsigned char length);



#endif /* SERIAL_H_ */