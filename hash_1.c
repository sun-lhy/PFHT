#include <stdio.h>  
#include <stdlib.h>  

#define uint8_t unsigned char  
#define uint16_t unsigned short  
#define uint32_t unsigned long 

#define HASH_TABLE_LEN  100  


/********************************************************************* 
*                           ���ݽṹ 
**********************************************************************/  
//����ڵ� 
typedef struct _Link_Node    
{    
    uint8_t temp;  
	unit16_t h_temp;
    struct _Link_Node *next;    
}Link_Node,*Link_Node_Ptr; 

//��ϣ��ͷ  
typedef struct _Hash_Header    
{    
	uint32_t  counter;
    struct _Link_Node *next;    
}Hash_Header,*Hash_Header_Ptr; 

/********************************************************************* 
*                           ȫ�ֱ��� 
**********************************************************************/  
  
//��ϣ��  
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];  

/********************************************************************* 
*                           ���� 
**********************************************************************/ 








  