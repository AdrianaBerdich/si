/*
 * aes_enc.h
 *
 * Created: 4/29/2016 5:09:29 PM
 *  Author: User
 */ 


#ifndef AES_ENC_H_
#define AES_ENC_H_


#include "aes_types.h"
#include <stdint.h>


void aes_encrypt_core(aes_cipher_state_t *state, const aes_genctx_t *ks, uint8_t rounds);




#endif /* AES_ENC_H_ */