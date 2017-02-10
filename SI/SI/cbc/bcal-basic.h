/*
 * bcal_basic.h
 *
 * Created: 5/11/2016 7:30:40 PM
 *  Author: User
 */ 


#ifndef BCAL-BASIC_H_
#define BCAL-BASIC_H_


#include <stdlib.h>
#include <stdint.h>
#include "blockcipher_descriptor.h"
#include "keysize_descriptor.h"
#include <avr/pgmspace.h>

uint8_t bcal_cipher_init(const bcdesc_t* cipher_descriptor,
const void* key, uint16_t keysize_b, bcgen_ctx_t* ctx);
void bcal_cipher_free(bcgen_ctx_t* ctx);
void bcal_cipher_enc(void* block, const bcgen_ctx_t* ctx);
void bcal_cipher_dec(void* block, const bcgen_ctx_t* ctx);
uint16_t bcal_cipher_getBlocksize_b(const bcdesc_t* desc);
PGM_VOID_P bcal_cipher_getKeysizeDesc(const bcdesc_t* desc);


#endif /* BCAL-BASIC_H_ */