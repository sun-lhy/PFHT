#include "hash.h"


#define HASH_TABLE_LEN  10  
#define HASH_FUN_COUNT  3  

/********************************************************************* 
*                           全局变量 
**********************************************************************/  

//哈希表  
Hash_Header_Ptr Hash_Table[HASH_TABLE_LEN];  

void initTable()
{
	int i;
	for(i=0;i<HASH_TABLE_LEN;i++)
	{
		Hash_Table[i] = (Hash_Header_Ptr)malloc(sizeof(Hash_Header));
		Hash_Table[i]->counter = 0;
		Hash_Table[i]->node = NULL;
	}
}

/********************************************************************* 
*                           函数 
**********************************************************************/ 

//创建一个数据节点
Link_Node_Ptr createNode(char *data)
{
	Link_Node_Ptr node = (Link_Node_Ptr)malloc(sizeof(Link_Node));
	node->data = (char*)malloc(strlen(data));
	strcpy(node->data,data);
	node->next = NULL;
	return node;
}

//插入一个链表
Link_Node_Ptr insertNode(Link_Node_Ptr head,Link_Node_Ptr node)
{
	Link_Node_Ptr p = node;
	while(p->next!=NULL)p=p->next;
	p->next = head;
	return node;
}

//获取链表中的一个节点
Link_Node_Ptr getNode(Link_Node_Ptr *head)
{
	Link_Node_Ptr tmp = *head;
	if(tmp==NULL)
	{
		return NULL;
	}else{
		Link_Node_Ptr node = tmp;
		*head = tmp->next;
		node->next = NULL;
		return node;
	}
}

void printNode(Link_Node_Ptr head)
{
	Link_Node_Ptr p = head;
	while(p!=NULL){
		printf("===>%s",p->data);
		p=p->next;
	}
}

//比较前面的hash值是否有相同，有一样的表示不可取，返回1，没有相同的返回0

int hashCompare(int i,Link_Node_Ptr x)
{
	int j;
	for(j=0;j<i;j++)
	{
		if(hashFun(j,(uint8_t *)x->data,strlen(x->data),HASH_TABLE_LEN)==hashFun(i,(uint8_t *)x->data,strlen(x->data),HASH_TABLE_LEN))return 1;
	}
	return 0;
}

//找到对应hash值最小的第一个bucket
int hashMinIndex(Link_Node_Ptr node)
{
	int i,j,index;
	uint32_t k;
	int min[HASH_FUN_COUNT];
	for(i=0;i<HASH_FUN_COUNT;i++)
	{
		min[i] = hashFun(i,(uint8_t*)node->data,strlen(node->data),HASH_TABLE_LEN);
	}
	k = uint32_t_max;
	for(j=0;j<HASH_FUN_COUNT;j++)
	{
		if(k>=Hash_Table[min[j]]->counter)
		{
			k = Hash_Table[min[j]]->counter;
		}
	}
	index = HASH_TABLE_LEN;
	for(j=0;j<HASH_FUN_COUNT;j++)
	{
		if(k==Hash_Table[min[j]]->counter && index>=min[j])
		{
			index = min[j];
		}
	}
	return index;
}

void insertItem(char *data)
{
	int i;
	int index;
	Link_Node_Ptr node;
	Link_Node_Ptr x = createNode(data);
	Link_Node_Ptr Y = insertNode(NULL,x);
	for(i=0;i<HASH_FUN_COUNT;i++)
	{
		if(hashCompare(i,x)==0)
		{
			int bucket = hashFun(i,(uint8_t*)x->data,strlen(x->data),HASH_TABLE_LEN);
			Y = insertNode(Hash_Table[bucket]->node,Y);
			Hash_Table[bucket]->node = NULL;
			Hash_Table[bucket]->counter ++;
		}
	}
	while((node=getNode(&Y)))
	{
		index = hashMinIndex(node);
		Hash_Table[index]->node = insertNode(Hash_Table[index]->node,node);
	}	
}

void printTable()
{
	int i;
	for(i=0;i<HASH_TABLE_LEN;i++)
	{
		printf("[%d]: (%d)",i,Hash_Table[i]->counter);
		printNode(Hash_Table[i]->node);
		printf("\n");
	}
}


void main()
{
	initTable();
	char s[]="123";
	//insertItem(s);
//	printTable();
	printf("\n");
	char s2[]="233";
	insertItem(s2);
	printTable();
	printf("\n");
	char s3[]="233";
	insertItem(s3);
	printTable();
	printf("\n");
}