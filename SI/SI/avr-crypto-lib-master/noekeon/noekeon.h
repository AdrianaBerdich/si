/* noekeon.h */
/*
    This file is part of the AVR-Crypto-Lib.
    Copyright (C) 2008  Daniel Otte (daniel.otte@rub.de)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef NOEKEON_H_
#define NOEKEON_H_

/**
 * \file    noekeon.h
 * \author  Daniel Otte
 * \email   daniel.otte@rub.de
 * \date    2008-04-11
 * \license GPLv3 or later
 * \brief Implementation of the Noekeon block cipher
 * \ingroup Noekeon
 * This is an implementation of the Noekeon block cipher.
 * For more details on Noekeon see http://gro.noekeon.org/
 */

#include <stdint.h>

/** \typedef noekeon_ctx_t
 * \brief holds key data for indirect mode
 *  
 * A variable of this type may hold the key data for the indirect mode.
 * For direct mode simply pass the key directly to the encryption or
 * decryption function.
 */
typedef uint8_t noekeon_ctx_t[16];

/** \fn void noekeon_enc(void *buffer, const void *key)
 * \brief noekeon encrytion funtion
 * 
 * This function encrypts a block (64 bit = 8 byte) with the noekeon encrytion
 * algorithm. Due to the two modes of noekeon (direct mode and indirect mode)
 * the second parameter either points directly to the key (direct mode) or to a
 * context generated by the noekeon_init() function (indirect mode).
 * \param buffer pointer to the 64 bit (8 byte) block to encrypt
 * \param key    pointer to either the key (128 bit = 16 byte; direct mode) or 
 * to the context (indirect mode)
 */
void noekeon_enc(void *buffer, const void *key);

/** \fn void noekeon_dec(void *buffer, const void *key)
 * \brief noekeon encrytion funtion
 * 
 * This function decrypts a block (64 bit = 8 byte) encrypted with the noekeon 
 * encrytion algorithm. Due to the two modes of noekeon (direct mode and 
 * indirect mode) the second parameter either points directly to the key 
 * (direct mode) or to a context generated by the noekeon_init() function 
 * (indirect mode).
 * \param buffer pointer to the 64 bit (8 byte) block to decrypt
 * \param key    pointer to either the key (128 bit = 16 byte; direct mode) or 
 * to the context (indirect mode)
 */
void noekeon_dec(void *buffer, const void *key);


/** \fn void noekeon_init(const void *key, noekeon_ctx_t *ctx)
 * \brief noekeon context generation function for indirect mode
 * 
 * This function generates a context from the supplied key for using
 * noekeon in indirect mode. For using noekeon in direct mode supply the key
 * direct to the noekeon_enc() and noekeon_dec() functions.
 * \param key pointer to the key (128 bit = 16 byte)
 * \param ctx pointer to the context to fill with key material 
 * to the context (indirect mode)
 */
void noekeon_init(const void *key, noekeon_ctx_t *ctx);

#endif /*NOEKEON_H_*/