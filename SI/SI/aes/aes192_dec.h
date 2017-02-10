/*
 * aes192_dec.h
 *
 * Created: 4/29/2016 5:12:33 PM
 *  Author: User
 */ 


#ifndef AES192_DEC_H_
#define AES192_DEC_H_



#include "aes_types.h"
#include "aes_dec.h"

/**
 * \brief decrypt with 192 bit key.
 *
 * This function decrypts one block with the AES algorithm under control of
 * a keyschedule produced from a 192 bit key.
 * \param buffer pointer to the block to decrypt
 * \param ctx    pointer to the key schedule
 */
void aes192_dec(void *buffer, aes192_ctx_t *ctx);




#endif /* AES192_DEC_H_ */