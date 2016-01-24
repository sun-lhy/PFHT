/* hash.h */
#ifndef _HASH_H_
#define _HASH_H_


#include <malloc.h>
#include "hashFunc.h"

/********************************************************************* 
*                           数据结构 
**********************************************************************/  
//链表节点 
typedef struct _Link_Node    
{    
    char *data;
    struct _Link_Node *next;    
}Link_Node,*Link_Node_Ptr; 

//哈希表头  
typedef struct _Hash_Header    
{    
	uint32_t counter;
    struct _Link_Node *node;    
}Hash_Header,*Hash_Header_Ptr; 

#endif /* _MYHEAD_H_ */