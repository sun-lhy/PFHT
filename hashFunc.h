/* hashFunc.h */
#ifndef _HASHFUNC_H_
#define _HASHFUNC_H_


#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

#define uint8_t unsigned char  
#define uint16_t unsigned short  
#define uint32_t unsigned long 

int additiveHash(uint8_t *buffer, int length, int size);
int bernstein(uint8_t *buffer, int length, int size);
int hashcode(uint8_t *buffer, int length, int size);

#endif /* _MYHEAD_H_ */
