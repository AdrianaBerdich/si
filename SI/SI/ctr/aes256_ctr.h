/*
 * aes256_ctr.h
 *
 * Created: 5/11/2016 8:53:59 PM
 *  Author: User
 */ 


#ifndef AES256_CTR_H_
#define AES256_CTR_H_


#include <stdint.h>
#include "aes_ctr.h"

/*! \struct aes256CtrCtx_t
*   \brief CTX data type
*/
typedef struct
{
	aes256_ctx_t aesCtx; /*!< aes256 context */
	uint8_t ctr[16]; /*!< the value of the counter */
	uint8_t cipherstream[16]; /*!< current ctr encryption output */
	uint8_t cipherstreamAvailable; /*!< available bytes to xor with new data bytes */
}aes256CtrCtx_t;

// USEFUL functions
void aesIncrementCtr(uint8_t *ctr, uint8_t len);
void aesXorVectors(uint8_t *dest, const uint8_t *src, uint8_t nbytes);
int8_t aesCtrCompare(uint8_t *ctr1, uint8_t *ctr2, uint8_t len);

// STREAM CTR functions
void aes256CtrInit(aes256CtrCtx_t *ctx, const uint8_t *key, const uint8_t *iv, uint8_t ivLen);
void aes256CtrSetIv(aes256CtrCtx_t *ctx, const uint8_t *iv, uint8_t ivLen);
void aes256CtrEncrypt(aes256CtrCtx_t *ctx, uint8_t *data, uint16_t dataLen);
void aes256CtrDecrypt(aes256CtrCtx_t *ctx, uint8_t *data, uint16_t dataLen);
void aes256CtrClean(aes256CtrCtx_t *ctx);

// DEFINES
#define AES256_CTR_LENGTH   16


#endif /* AES256_CTR_H_ */