/*
 * aes_ctr.h
 *
 * Created: 5/11/2016 8:59:06 PM
 *  Author: User
 */ 


#ifndef AES_CTR_H_
#define AES_CTR_H_


#include <stdint.h>
#include <avr/pgmspace.h>

#ifdef __cplusplus
extern "C" {
	#endif

	typedef struct {
		uint8_t key[32];
		uint8_t enckey[32];
		uint8_t deckey[32];
	} aes256_context;

	void aes256_init_ecb(aes256_context *, uint8_t * /* key */);
	void aes256_done(aes256_context *);
	void aes256_encrypt_ecb(aes256_context *, uint8_t * /* plaintext */);
	void aes256_decrypt_ecb(aes256_context *, uint8_t * /* cipertext */);

	#define aes256_ctx_t aes256_context

	#define aes256_init(x,y)	aes256_init_ecb((y),(uint8_t*)(x))
	#define aes256_enc(x,y)		aes256_encrypt_ecb((y),(uint8_t*)(x))
	#define aes256_dec(x,y)		aes256_decrypt_ecb((y),(uint8_t*)(x))

	#ifdef __cplusplus
}
#endif



#endif /* AES_CTR_H_ */