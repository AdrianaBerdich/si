/*
 * serial.h
 *
 * Created: 5/1/2016 11:00:13 PM
 *  Author: User
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_


extern void USART_Init( unsigned int BAUDRATE);
extern void USART_Transmit( unsigned char data );
extern unsigned char USART_Receive( void );
extern void UsartWrite(unsigned char *data, unsigned char length);
extern void USART_send_str(char *data);


#endif /* SERIAL_H_ */