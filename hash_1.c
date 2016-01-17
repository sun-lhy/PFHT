#include <stdio.h>  
#include <stdlib.h>  

#define uint8_t unsigned char  
#define uint16_t unsigned short  
#define uint32_t unsigned long 

#define HASH_TABLE_LEN  100  


/********************************************************************* 
*                           数据结构 
**********************************************************************/  
//链表节点 
typedef struct _Link_Node    
{    
    uint8_t temp;  
	unit16_t h_temp;
    struct _Link_Node *next;    
}Link_Node,*Link_Node_Ptr; 

//哈希表头  
typedef struct _Hash_Header    
{    
	uint32_t  counter;
    struct _Link_Node *next;    
}Hash_Header,*Hash_Header_Ptr; 

/********************************************************************* 
*                           全局变量 
**********************************************************************/  
  
//哈希表  
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];  

/********************************************************************* 
*                           函数 
**********************************************************************/ 








  