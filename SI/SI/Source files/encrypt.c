/*
 * encrypt.c
 *
 * Created: 5/9/2016 6:14:14 PM
 *  Author: User
 */ 
#include "aes/aes.h"
#include "adc.h"
#include "serial.h"
#include "encrypt.h"
#include "conversion.h"

//#define DEBUGPROIECT
//#define DECRYPT
#define DECRYPT_8B

char buffer1[10];
char buffer2[10];


void encrypt(void)
{
	uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21, 22,23,24,25,26,27,28,29,30,31};

	/*uint16_t a = ReadADC(0);
	uint8_t data[16]={a&0xff, (a>>8)&0xff};
	//uint8_t value[16];
	for(int i=0; i<16; i++)
	//value[16] = (a >> 8*i) & 0xFF;
	data[16] = (a >> 8*i) & 0xFF;//IntToByte();//{a, (a>>8)};//"text to encrypt";
		*/
	uint8_t	 a = (uint8_t)((50 * ReadADC(0))/1023);
//sprintf(buff, "%d", a);
	//uint16_t a = ReadADC(0);
	//uint8_t data[16] = "ana are mere";         
	uint8_t data[16] ;//= { a };// toArray(100 * ReadADC(0)/1023);
	//	data[1] = a & 0xFF;
			//static uint8_t data[2] = { 0x00, 0x00 }; //ecb, cbc, counter mode https://github.com/cantora/avr-crypto-lib/blob/master/USAGE.blockciphers
//
			//*(data) = (a>> 8) & 0x00FF;
			//data[1] = a & 0x00FF;
		//	uint8_t data[]= {34, 0, 0, 0};
	memset(data, 0, sizeof(data));
	sprintf(data, "%d", a);
	
	
#ifdef DEBUGPROIECT
		
	USART_Transmit(data[0]);
	USART_Transmit(data[1]);
	USART_Transmit(data[2]);
	USART_Transmit(data[3]);
	USART_send_str("\n");

	memset(buffer1,0,sizeof(buffer1));
	sprintf(buffer1, "%s\n", data);
	USART_Transmit(buffer1[0]);
	USART_Transmit(buffer1[1]);
	USART_Transmit(buffer1[2]);
	USART_Transmit(buffer1[3]);

	USART_Transmit(buffer1[4]);
	USART_Transmit(buffer1[5]);

	USART_Transmit(buffer1[6]);
	USART_Transmit(buffer1[7]);
	USART_Transmit(buffer1[8]);
	USART_Transmit(buffer1[9]);
	USART_send_str("\n");
	
#endif


	aes256_ctx_t ctx;
	aes256_init(key, &ctx);
	aes256_enc(data, &ctx);
	//UART_send_str("Encrypted: '");
	print_hex(data, 16);
	USART_send_str("\n");

#ifdef DECRYPT

	aes256_dec(data, &ctx);
	USART_send_str("Decrypted: ");
				
	memset(buffer2,0,sizeof(buffer2));
	sprintf(buffer2, "%s\n", data);
	USART_Transmit(buffer2[0]);
	USART_Transmit(buffer2[1]);
	USART_Transmit(buffer2[2]);
	USART_Transmit(buffer2[3]);
	
	USART_Transmit(buffer2[4]);
	USART_Transmit(buffer2[5]);

	USART_Transmit(buffer2[6]);
	USART_Transmit(buffer2[7]);
	USART_Transmit(buffer2[8]);
	USART_Transmit(buffer2[9]);
	USART_send_str("\n");
		
#endif

}

void decrypt_ecb()
{
	uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21, 22,23,24,25,26,27,28,29,30,31};
	uint8_t dataa[16] ="98434AF57B353F83620DBDD75E1EF5AC";//0A8F679D9DDD1DFD8227B21A83FD4B15" ;
	aes256_ctx_t ctx;
	//aes256_init(key, &ctx);
	//aes256_enc(dataa, &ctx);
	//print_hex(dataa,16);
	aes256_dec(dataa, &ctx);
	USART_send_str(dataa);

		//memset(buffer2,0,sizeof(buffer2));
		//sprintf(buffer2, "%s\n", data);
		//USART_Transmit(buffer2[0]);
		//USART_Transmit(buffer2[1]);
		//USART_Transmit(buffer2[2]);
		//USART_Transmit(buffer2[3]);
		//
		//USART_Transmit(buffer2[4]);
		//USART_Transmit(buffer2[5]);
//
		//USART_Transmit(buffer2[6]);
		//USART_Transmit(buffer2[7]);
		//USART_Transmit(buffer2[8]);
		//USART_Transmit(buffer2[9]);
		USART_send_str("\n");
	
}

void encrypt_8b(void)
{
	uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21, 22,23,24,25,26,27,28,29,30,31};

	/*uint16_t a = ReadADC(0);
	uint8_t data[16]={a&0xff, (a>>8)&0xff};
	//uint8_t value[16];
	for(int i=0; i<16; i++)
	//value[16] = (a >> 8*i) & 0xFF;
	data[16] = (a >> 8*i) & 0xFF;//IntToByte();//{a, (a>>8)};//"text to encrypt";
		*/
	uint8_t	 a = (uint8_t)((50 * ReadADC(0))/1023);
//sprintf(buff, "%d", a);
	//uint16_t a = ReadADC(0);
	//uint8_t data[16] = "ana are mere";         
	uint8_t data[16] ;//= { a };// toArray(100 * ReadADC(0)/1023);
	//	data[1] = a & 0xFF;
			//static uint8_t data[2] = { 0x00, 0x00 }; //ecb, cbc, counter mode https://github.com/cantora/avr-crypto-lib/blob/master/USAGE.blockciphers
//
			//*(data) = (a>> 8) & 0x00FF;
			//data[1] = a & 0x00FF;
		//	uint8_t data[]= {34, 0, 0, 0};
	memset(data, 0, sizeof(data));
	sprintf(data, "%d", a);



	aes256_ctx_t ctx;
	aes256_init(key, &ctx);
	aes256_enc(data, &ctx);
	//UART_send_str("Encrypted: '");
	print_hex(data, 16);
	USART_send_str("\n");

#ifdef DECRYPT_8B

	aes256_dec(data, &ctx);
	USART_send_str("Decrypted: ");
				
	memset(buffer2,0,sizeof(buffer2));
	sprintf(buffer2, "%s\n", data);
	USART_Transmit(buffer2[0]);
	USART_Transmit(buffer2[1]);
	USART_Transmit(buffer2[2]);
	USART_Transmit(buffer2[3]);
	
	USART_Transmit(buffer2[4]);
	USART_Transmit(buffer2[5]);

	USART_Transmit(buffer2[6]);
	USART_Transmit(buffer2[7]);
	USART_Transmit(buffer2[8]);
	USART_Transmit(buffer2[9]);
	USART_send_str("\n");
		
#endif

}
