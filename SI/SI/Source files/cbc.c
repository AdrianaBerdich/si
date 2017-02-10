/*
 * cbc.c
 *
 * Created: 5/11/2016 7:52:23 PM
 *  Author: User
 */ 
#include <avr/io.h>
#include "aes/aes.h"
#include "adc.h"
#include "serial.h"
#include "encrypt.h"
#include "bcal-cbc.h"
#include "bcal_aes256.h"

//#define CBCDecrypt;
char buffer2[20];

	
	uint8_t key[32] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21, 22,23,24,25,26,27,28,29,30,31};
	
	uint8_t iv[]  = {   0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f
	
	};
	aes256_ctx_t ctx;
	bcal_cbc_ctx_t bctx;
	uint8_t i;
	
	void unprint(char* string, uint8_t n) {
			for(i = 0; i < n; ++i) {
					while(!(UCSR0A & (1<<UDRE0)));
					UDR0 = string[i];
			}
	}
	
void cbc()
{
		uint8_t	 a = (uint8_t)((50 * ReadADC(0))/1023);
		uint8_t bdata[16] ;
		memset(bdata, 0, sizeof(bdata));
		sprintf(bdata, "%d", a);
			bcal_cbc_init(&aes256_desc, key, 256, &bctx);
			bcal_cbc_encMsg(iv, bdata, 4, &bctx);
			
			print_hex(bdata, 16);
			USART_send_str("\n");
		
			bcal_cbc_decMsg(iv, bdata, 4, &bctx);
		
#ifdef CBCDecrypt
		USART_send_str("Decrypted: ");
		
		memset(buffer2,0,sizeof(buffer2));
		sprintf(buffer2, "%s\n", bdata);
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
			
		
			bcal_cbc_free(&bctx);
		
}