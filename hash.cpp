#include "hash.h"


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
	if(p==NULL)return head;		//误漏
	while(p->next!=NULL)p=p->next;
	p->next = head;
	return node;
}

//删除一个链表
Link_Node_Ptr deleteNode(Link_Node_Ptr head,Link_Node_Ptr node)
{
	if(head==NULL)return head;
	Link_Node_Ptr p=head;
	Link_Node_Ptr q=p->next;
	
	//删除头节点
	if(strcmp(p->data,node->data)==0)
	{
		head=p->next;
		free(p);
	}
	else	//删除非头节点
	{
		while(q!=NULL)
		{
			if(strcmp(q->data,node->data)==0)
			{	
				p->next=q->next;
				free(q);
				break;
			}		
			p=q;
			q=q->next;	
		}
	}
	return head;
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



