/* hash.h */
#ifndef _HASH_H_
#define _HASH_H_


#include <malloc.h>
#include "hashFunc.h"

/********************************************************************* 
*                           ���ݽṹ 
**********************************************************************/  
//����ڵ� 
typedef struct _Link_Node    
{    
    char *data;
    struct _Link_Node *next;    
}Link_Node,*Link_Node_Ptr; 

//��ϣ��ͷ  
typedef struct _Hash_Header    
{    
	uint32_t counter;
    struct _Link_Node *node;    
}Hash_Header,*Hash_Header_Ptr; 

#endif /* _MYHEAD_H_ */