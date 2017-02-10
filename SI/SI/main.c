/*
 * SI.c
 *
 * Created: 4/29/2016 4:54:24 PM
 * Author : User
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "aes/aes.h"
#include "adc.h"
#include "serial.h"
#include "encrypt.h"
#include "bcal-cbc.h"
#include "bcal_aes256.h"
#include "cbc.h"

#include "aes_ctr.h"
#include "aes256_ctr.h"
#include "ctr.h"


char REC;


int main(void)
{
	InitADC();
	USART_Init(103);
//char *data;
//sei();
	while(1)
	{
		//ctr_enc();
		//cbc();
		//encrypt();
		ctr_enc_8b();
		
		
		
		//decrypt_ecb();
	//	ctr_dec();
		
		//encrypt_8b();
/*		int i = 0;
		if (REC != 0) {
			if (REC == '\n') {
				// do whatever you want with the array contents
				i =0;
				data[0] = 0;
				} else {
				data[i++] = REC;
			}
			REC = 0;
		}
		
//	uint8_t dat[16] = "9F3B7504926F8BD36E3118E903A4CD4A";
	decrypt_ecb();
//		USART_send_str(dat);		//http://electronics.stackexchange.com/questions/161242/receiving-a-whole-string-from-usart-on-atmega16
//		USART_send_str("\n");
	    //USART_Transmit("\n");		*/
	}

	return 0;
}
ISR(USART_RX_vect)
{
	REC = UDR0;
}



