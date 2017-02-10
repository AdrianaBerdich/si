/*
 * keysize_descriptor.h
 *
 * Created: 5/11/2016 7:33:46 PM
 *  Author: User
 */ 


#ifndef KEYSIZE_DESCRIPTOR_H_
#define KEYSIZE_DESCRIPTOR_H_


#include <stdint.h>
#include <avr/pgmspace.h>

#define KS_TYPE_TERMINATOR 0x00
#define KS_TYPE_LIST       0x01
#define KS_TYPE_RANGE      0x02
#define KS_TYPE_ARG_RANGE  0x03

#define KS_INT(a) ((a)&0xFF), ((a)>>8)

typedef struct{ /* keysize is valid if listed in items */
	uint8_t  n_items;  /* number of items (value 0 is reserved) */
	uint16_t items[]; /* list of valid lengths */
}keysize_desc_list_t;

typedef struct{ /* keysize is valid if min<=keysize<=max */
	uint16_t min;
	uint16_t max;
}keysize_desc_range_t;

typedef struct{ /* keysize is valid if min<=keysize<=max and if keysize mod distance == offset */
	uint16_t min;
	uint16_t max;
	uint16_t distance;
	uint16_t offset;
}keysize_desc_arg_range_t;

uint8_t is_valid_keysize_P(PGM_VOID_P ks_desc, uint16_t keysize);
uint16_t get_keysize(PGM_VOID_P ks_desc);
uint16_t get_keysizes(PGM_VOID_P ks_desc, uint16_t** list);


#endif /* KEYSIZE_DESCRIPTOR_H_ */