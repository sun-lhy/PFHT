#include "hash.h"


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

void deleteItem(char *data)
{
	int i;
	int index;
	Link_Node_Ptr node;
	Link_Node_Ptr x = createNode(data);
	Link_Node_Ptr Y = NULL;
	for(i=0;i<HASH_FUN_COUNT;i++)
	{
		if(hashCompare(i,x)==0)
		{
			int bucket = hashFun(i,(uint8_t*)x->data,strlen(x->data),HASH_TABLE_LEN);
			Hash_Table[bucket]->node = deleteNode(Hash_Table[bucket]->node,x);
			Hash_Table[bucket]->counter --;
			Y = insertNode(Hash_Table[bucket]->node,Y);
			Hash_Table[bucket]->node = NULL;
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
	insertItem(s);
	printTable();
	printf("\n");
	char s2[]="233";
	insertItem(s2);
	printTable();
	printf("\n");
	char s3[]="234";
	insertItem(s3);
	printTable();
	
	printf("\n");
	
	deleteItem(s);
	printTable();
	printf("\n");

	/*
	Link_Node_Ptr Y = NULL;
	char s[] = "avc";
	Link_Node_Ptr node = createNode(s);
	Y = insertNode(Y,node);
	char s5[] = "ac";
	node = createNode(s5);
	Y = insertNode(Y,node);
	char s2[] = "ayc";
	node = createNode(s2);
	Y = insertNode(Y,node);
	printNode(Y);
	printf("\n\n");
	char s1[] = "a4c";
	node = createNode(s1);
	Y = deleteNode(Y,node);
	printNode(Y);
	printf("\n\n");
	*/
}

