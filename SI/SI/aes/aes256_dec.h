/*
 * aes256_dec.h
 *
 * Created: 4/29/2016 5:10:39 PM
 *  Author: User
 */ 


#ifndef AES256_DEC_H_
#define AES256_DEC_H_


#include "aes_types.h"
#include "aes_dec.h"

/**
 * \brief decrypt with 256 bit key.
 *
 * This function decrypts one block with the AES algorithm under control of
 * a keyschedule produced from a 256 bit key.
 * \param buffer pointer to the block to decrypt
 * \param ctx    pointer to the key schedule
 */
void aes256_dec(void *buffer, aes256_ctx_t *ctx);




#endif /* AES256_DEC_H_ */