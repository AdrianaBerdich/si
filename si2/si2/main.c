/*
 * si2.c
 *
 * Created: 4/27/2016 9:47:39 PM
 * Author : User
 */ 

#include <avr/io.h>
#include "adc.h"
#include "aes/aes.h";
#include "serial.h"
#include "aes.h"
#include "aes256_enc.h"
#include "aes256_dec.h"



// prototype functions
//static void UART_init(void);
//static void UART_send_char(char c);
//static void UART_send_str(char *str);
//static void test(void);
//static char hexa_to_ascii(uint8_t input);
//static void print_hex(uint8_t *ptr, uint8_t size);

int main(void)
{
	uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20, 21,22,23,24,25,26,27,28,29,30,31};
		uint8_t data[16] = "text to encrypt";
		aes256_ctx_t ctx;
		aes256_init(key, &ctx);
// init UART
USART_Init(304);

while(1)
{
// encrypt and decrypt the message with the key

}

return 0;
}

//void aes256_test(void)
//{
	//// aes256 is 32 byte key
	//uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20, 21,22,23,24,25,26,27,28,29,30,31};
//
	//// aes256 is 16 byte data size
	//uint8_t data[16] = "text to encrypt";
//
	//// declare the context where the round keys are stored
	//aes256_ctx_t ctx;
//
	//// Initialize the AES256 with the desired key
	//aes256_init(key, &ctx);
//
	//// Encrypt data
	//// "text to encrypt" (ascii) -> '9798D10A63E4E167122C4C07AF49C3A9'(hexa)
	//aes256_enc(data, &ctx);
//
	//// Decrypt data
	//// '9798D10A63E4E167122C4C07AF49C3A9'(hexa) -> "text to encrypt" (ascii)
	//aes256_dec(data, &ctx);
//}
//
//
//
///*!	\fn 	int main(void)
//*	\brief	Main functon
//*/
//int main(void)
//{
	//// init UART
	//UART_init();
//
	//while(1)
	//{
		//// encrypt and decrypt the message with the key
		//aes256_test();
	//}
//
	//return 0;
//}
//
///*!	\fn 	static void UART_init(void)
//*	\brief	Init UART to 19200 baudrate
//*/
//static void UART_init(void)
//{
	//// U2Xn to 1
	//UCSR0A = (1<<U2X0);
//
	//// configure Baudrate to 19200 with U2X0 enabled
	//UBRR0L = 103;
	//UBRR0H = 0;
//
	//UCSR0B = (1<<TXEN0);
	//UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
//}
//
///*!	\fn 	static void UART_send_char(char c)
//*	\brief	Send a char through UART0
//*/
//static void UART_send_char(char c)
//{
	//// wait until the last char has been sent
	//while(!(UCSR0A & (1<<UDRE0)));
//
	//// load the new char to transmit
	//UDR0 = c;
//}
//
///*!	\fn 	static void UART_send_str(char *str);
//*	\brief	Send a string through UART0
//*/
//static void UART_send_str(char *data)
//{
	//while(*data != 0)
	//{
		//UART_send_char(*data++);
	//}
//}
//
///*!	\fn 	static test(uint8_t input)
//*	\brief	Example of use AVR-cryptolib libraries.
//*/
//void test(void)
//{
	//// aes256 is 32 byte key
	//uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21, 22,23,24,25,26,27,28,29,30,31};
//
	//// aes256 is 16 byte data size
	//uint8_t data[16] = "text to encrypt";
//
	//// the context where the round keys are stored
	//aes256_ctx_t ctx;
//
	//UART_send_str("\n** AES256-TEST **\n");
//
	//// Initialize the AES256 with the desired key
	//aes256_init(key, &ctx);
	//UART_send_str("Key: '");
	//print_hex(key, 32);
	//UART_send_str("'\n");
//
	//// Encrypt text and show the result in hexa
	//aes256_enc(data, &ctx);
	//UART_send_str("Encrypted: '");
	//print_hex(data, 16);
	//UART_send_str("'\n");
//
	//// Decrypt data and show the result in ascii
	//aes256_dec(data, &ctx);
	//UART_send_str("Decrypted: '");
	//UART_send_str(data);
	//UART_send_str("'\n");
//
//}
//
///*!	\fn 	static char hexa_to_ascii(uint8_t input)
//*	\brief	Convert the lower nibble of hexa number to his ascii
//*           representation. Usefull to print hexadecimal
//*           values trought UART.\n
//*           For example: hexa_to_ascii(0x0A) would return ascii 'A'.
//*
//*   \param  uint8_t input - The value to be converted
//*   \return char - The ascii representation of the lower nibble of the input
//*/
//static char hexa_to_ascii(uint8_t input)
//{
//
	//input &= 0x0F;
//
	//if (input < 10)
	//{
		//input = input + '0';
	//}
	//else
	//{
		//input = input + 'A' - 10;
	//}
//
	//return (char)input;
//}
//
///*!	\fn 	static void print_hex(uint8_t *ptr, uint8_t size)
//*	\brief	Print hexadecimal representation of an array of uint8_t.
//*
//*   \param  uint8_t *ptr - The pointer to the array of uint8_t
//*   \param  uint8_t size - The size of the array
//*/
//static void print_hex(uint8_t *ptr, uint8_t size)
//{
	//uint8_t i;
//
	//for(i=0; i<size; i++)     {         UART_send_char(hexa_to_ascii(ptr[i]>>4));
		//UART_send_char(hexa_to_ascii(ptr[i]&0x0F));
	//}
//}
////int main(void)
////{
    /////* Replace with your application code */
    ////while (1) 
    ////{
		////
    ////}
	////
////}

