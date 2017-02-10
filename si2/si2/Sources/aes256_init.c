/*
 * aes256_init.c
 *
 * Created: 4/27/2016 11:20:57 PM
 *  Author: User
 */ 
#include "aes.h"
#include "aes_dec.h"

void aes256_dec(void *buffer, aes256_ctx_t *ctx){
	aes_decrypt_core(buffer, (aes_genctx_t*)ctx, 14);
}