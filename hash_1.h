/*hash_1.h*/
#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include "hashFunc.h"


//链表节点 
typedef struct _Link_Node    
{    
	char  data;
    struct _Link_Node *next;   
	
}Link_Node,*Link_Node_Ptr; 

//哈希表头  
typedef struct _Hash_Header    
{    
	uint32_t  counter;
    struct _Link_Node *next;  

}Hash_Header,*Hash_Header_Ptr; 



Hash_Header_Ptr Insert_link(Hash_Header_Ptr  header,Link_Node_Ptr node);
Hash_Header_Ptr Delet_link(Hash_Header_Ptr  header,Link_Node_Ptr node);



#endif
