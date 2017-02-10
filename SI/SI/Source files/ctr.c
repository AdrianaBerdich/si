/*
 * ctr.c
 *
 * Created: 5/11/2016 9:04:18 PM
 *  Author: User
 */ 
#include <avr/io.h>
#include "aes/aes.h"
#include "adc.h"
#include "serial.h"
#include "encrypt.h"
#include "bcal-cbc.h"
#include "bcal_aes256.h"
#include "cbc.h"

#include "aes_ctr.h"
#include "aes256_ctr.h"

//#define DECRYPT_CTR
//#define DECRYPT_CTR_8B

char buffer2[30];

static uint8_t key[32] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21, 22,23,24,25,26,27,28,29,30,31 };
static uint8_t iv[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	
static uint8_t key_b[4]={0,1,2,3};	
static uint8_t iv_b[2] ={0x00, 0x00};


//uint8_t text[32] = "Ana are mere";

void ctr_enc()
{
	uint8_t	 a = (uint8_t)((50 * ReadADC(0))/1023);
	uint8_t text[32] ;
	memset(text, 0, sizeof(text));
	sprintf(text, "%d", a);
	
    aes256CtrCtx_t ctx;
    aes256CtrInit(&ctx, key, iv, 16);

    aes256CtrEncrypt(&ctx, text, sizeof(text));
	//USART_send_str("\nkey: '");
	//print_hex(key, 16);
	//USART_send_str("\nctx: '");
	//print_hex(ctx, 16);
	//USART_send_str("\nEncrypted: '");
	print_hex(text, 16);
	USART_send_str("\n");
	
	 aes256CtrInit(&ctx, key, iv, 16);

#ifdef DECRYPT_CTR
   
    aes256CtrDecrypt(&ctx, text, sizeof(text));
	
	USART_send_str("Decrypted: ");
	
	memset(buffer2,0,sizeof(buffer2));
	sprintf(buffer2, "%s\n", text);
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
		USART_Transmit(buffer2[10]);
		USART_Transmit(buffer2[11]);
		USART_Transmit(buffer2[12]);
		USART_Transmit(buffer2[13]);
		
		USART_Transmit(buffer2[14]);
		USART_Transmit(buffer2[15]);

		USART_Transmit(buffer2[16]);
		USART_Transmit(buffer2[17]);
		USART_Transmit(buffer2[18]);
		USART_Transmit(buffer2[19]);
		USART_Transmit(buffer2[20]);
		USART_Transmit(buffer2[21]);
		USART_Transmit(buffer2[22]);
		USART_Transmit(buffer2[23]);
		
		USART_Transmit(buffer2[24]);
		USART_Transmit(buffer2[25]);

		USART_Transmit(buffer2[26]);
		USART_Transmit(buffer2[27]);
		USART_Transmit(buffer2[28]);
		USART_Transmit(buffer2[29]);
	USART_send_str("\n");
	
#endif

}

void ctr_enc_8b()
{
	uint8_t	 a = (uint8_t)((50 * ReadADC(0))/1023);
	uint8_t text[2] ;
	memset(text, 0, sizeof(text));
	sprintf(text, "%d", a);
	//USART_Transmit(sizeof(text));
	//USART_Transmit(text[0]);
	//USART_Transmit(text[1]);
	//USART_Transmit(text[2]);
	//USART_Transmit(text[3]);
	//USART_Transmit(text[4]);
	//USART_Transmit(text[5]);
//
//	USART_Transmit("\n");
	aes256CtrCtx_t ctx;
	aes256CtrInit(&ctx, key, iv, 16);

	aes256CtrEncrypt(&ctx, text, sizeof(text)) ;
	//uint8_t x[32] ;
	//strcpy(x, text);
	print_hex(text, 2);
	USART_send_str("\n");
	
	aes256CtrInit(&ctx, key, iv, 16);

#ifdef DECRYPT_CTR_8B

	//uint8_t txt[32]={text, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		//0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		//0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t txt[32];
	//memset(txt, 0, sizeof(txt));
	//sprintf(txt, "%s", text);
	//strcpy(txt, text);
	
	aes256CtrDecrypt(&ctx, text, sizeof(text));
	
	USART_send_str("Decrypted: ");
	
	memset(buffer2,0,sizeof(buffer2));
	sprintf(buffer2, "%s\n", text);
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
	USART_Transmit(buffer2[10]);
	USART_Transmit(buffer2[11]);
	USART_Transmit(buffer2[12]);
	USART_Transmit(buffer2[13]);
	
	USART_Transmit(buffer2[14]);
	USART_Transmit(buffer2[15]);

	USART_Transmit(buffer2[16]);
	USART_Transmit(buffer2[17]);
	USART_Transmit(buffer2[18]);
	USART_Transmit(buffer2[19]);
	USART_Transmit(buffer2[20]);
	USART_Transmit(buffer2[21]);
	USART_Transmit(buffer2[22]);
	USART_Transmit(buffer2[23]);
	
	USART_Transmit(buffer2[24]);
	USART_Transmit(buffer2[25]);

	USART_Transmit(buffer2[26]);
	USART_Transmit(buffer2[27]);
	USART_Transmit(buffer2[28]);
	USART_Transmit(buffer2[29]);
	USART_send_str("\n");
	
	#endif

}

void ctr_dec()
{
	uint8_t txt[16] = "C3A000B62A499FD0A9F39A6ADD2E7780";
	aes256CtrCtx_t ctx;
//	aes256CtrInit(&ctx, key, iv, 16);

//	aes256CtrEncrypt(&ctx, txt, sizeof(txt));
	//USART_send_str("\nkey: '");
	//print_hex(key, 16);
	//USART_send_str("\nctx: '");
	//print_hex(ctx, 16);
//	USART_send_str("\nEncrypted: '");
//	print_hex(txt, 16);
//	USART_send_str("\n");

//	#ifdef DECRYPT_CTR
//	aes256CtrInit(&ctx, key, iv, 16);
	aes256CtrDecrypt(&ctx, txt, sizeof(txt));
	
	USART_send_str("Decrypted: ");
	USART_send_str(txt);
}