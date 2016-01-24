/********************************************************************* 
*                          常用hash函数 
*                          (c)copyright
*                         All Right Reserved 
**********************************************************************/  
#include "hashFunc.h"

//加法hash
int additiveHash(uint8_t *buffer, int length, int size)
{
	int hash=0;
	int i;
	for (i = 0; i < length; i++)
	{
		hash += *(buffer+i);
	}
	return (hash % size);
}

//乘法hash
int bernstein(uint8_t *buffer, int length, int size)
{
	int a = 33;
	int hash = 0;
	int i;
	for (i = 0; i < length; i++) 
		hash = a*hash + *(buffer+i);
	return (hash % size);
}
 
//数组hash
int hashcode(uint8_t *buffer, int length, int size)
{
	int hash = 0;
	int i;
	for(i = 0; i < length; i++)
	{
		hash=((hash<<2)+(buffer[i]>>4))^(buffer[i]<<10);
	}
	hash = hash % size;
	hash = hash < 0 ? hash + size : hash;
	return hash;
}
/*
void main()
{
	char s[] = {1,1,1};
	int len = sizeof(s);
	int size = 100;
	int ans = hashcode((uint8_t *)s,len,size);
	printf("%d\n",ans);
}

*/



