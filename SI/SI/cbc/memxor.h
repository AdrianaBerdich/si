/*
 * memxor.h
 *
 * Created: 5/11/2016 7:37:35 PM
 *  Author: User
 */ 


#ifndef MEMXOR_H_
#define MEMXOR_H_


#include <stdint.h>

void memxor(void* dest, const void* src, uint16_t n);
void memxor_P(void* dest, const void* src, uint16_t n);


#endif /* MEMXOR_H_ */