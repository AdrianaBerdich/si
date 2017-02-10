/*
 * aes256_enc.h
 *
 * Created: 4/29/2016 5:11:15 PM
 *  Author: User
 */ 


#ifndef AES256_ENC_H_
#define AES256_ENC_H_


#include "aes_types.h"
#include "aes_enc.h"


/**
 * \brief encrypt with 256 bit key.
 *
 * This function encrypts one block with the AES algorithm under control of
 * a keyschedule produced from a 256 bit key.
 * \param buffer pointer to the block to encrypt
 * \param ctx    pointer to the key schedule
 */
void aes256_enc(void *buffer, aes256_ctx_t *ctx);




#endif /* AES256_ENC_H_ */