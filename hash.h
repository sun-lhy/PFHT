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


#define HASH_TABLE_LEN  10  
#define HASH_FUN_COUNT  3

Link_Node_Ptr createNode(char *data);
Link_Node_Ptr insertNode(Link_Node_Ptr head,Link_Node_Ptr node);
Link_Node_Ptr deleteNode(Link_Node_Ptr head,Link_Node_Ptr node);
Link_Node_Ptr getNode(Link_Node_Ptr *head);
void printNode(Link_Node_Ptr head);
int hashCompare(int i,Link_Node_Ptr x);

#endif /* _MYHEAD_H_ */