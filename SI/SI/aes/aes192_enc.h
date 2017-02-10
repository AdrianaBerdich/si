/*
 * aes192_enc.h
 *
 * Created: 4/29/2016 5:11:54 PM
 *  Author: User
 */ 


#ifndef AES192_ENC_H_
#define AES192_ENC_H_

#include "aes_types.h"
#include "aes_enc.h"


/**
 * \brief encrypt with 192 bit key.
 *
 * This function encrypts one block with the AES algorithm under control of
 * a keyschedule produced from a 192 bit key.
 * \param buffer pointer to the block to encrypt
 * \param ctx    pointer to the key schedule
 */
void aes192_enc(void *buffer, aes192_ctx_t *ctx);





#endif /* AES192_ENC_H_ */