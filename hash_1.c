#include <stdio.h>  
#include <stdlib.h>  
#include "hashFunc.h"
#include  "hash_1.h"
#define uint8_t unsigned char  
#define uint16_t unsigned short  
#define uint32_t unsigned long 

#define HASH_TABLE_LEN  100  


/********************************************************************* 
*                           数据结构 
**********************************************************************/  
/*
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

*/



/********************************************************************* 
*                           全局变量 
**********************************************************************/  
  
//哈希表  
Hash_Header_Ptr  Hash_Table[HASH_TABLE_LEN];  

/********************************************************************* 
*                           函数 
**********************************************************************/ 

Hash_Header_Ptr Insert_link(Hash_Header_Ptr  header,Link_Node_Ptr node)
{
	node->next=header->next;
	header->counter++;
	header->next=node;
	return header;

}
Hash_Header_Ptr Delet_link(Hash_Header_Ptr  header,Link_Node_Ptr node)
{
  Link_Node_Ptr p=header->next;
  Link_Node_Ptr q=p->next;
  if(p->data==node->data)
	  header->next=p->next;
  else
	 {
	  while(q!=NULL)
	  {
		  if(q->data==node->data)
		  {	p->next=q->next;
			free(q);
		  }
		  else
		  {	p=q;
			q=q->next;//节点后移
				break;
		  }
		  
	  }
  }
	  header->counter--;
		printf("删除成功\n");

  return header;
}


/*
void main()
{
	
	Hash_Header_Ptr header=(Hash_Header_Ptr)malloc(sizeof(Hash_Header));
	Link_Node_Ptr node=(Link_Node_Ptr)malloc(sizeof(Link_Node));
	node->data='c';
	header->counter=0;

    Insert_link(header,node);
   	printf("%d\n",header->counter);
	printf("%c\n",	node->data);
	Delet_link(header,node);
	printf("%d\n",header->counter);
	printf("%c\n",	node->data);
*/


































/*
void  insert_link(Link_Node_Ptr  new_node)
{
	
	 Link_Node_Ptr  node;
	 new_node->next = NULL;
   	int pos=hash % size;
	 if (Hash_Table[pos]->next == NULL)  
	 {
        Hash_Table[pos]->next = new_node;  
    }  
    else  
    {  
        node = Hash_Table[pos]->next;  
        while (node->next != NULL)  
        {  
            node = node->next;  
        }  
        node->next = new_node;  
    }  
}  

void main()
{
	Link_Node_Ptr node;  
	char s[] = {1};
	int len = sizeof(s);
	int size = 100;
	hashcode((uint8_t *)s,len,size); 
    node->data = 7;  
    insert_link(node);  
      
}

*/




  