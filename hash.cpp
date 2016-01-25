#include "hash.h"


/********************************************************************* 
*                           ���� 
**********************************************************************/ 

//����һ�����ݽڵ�
Link_Node_Ptr createNode(char *data)
{
	Link_Node_Ptr node = (Link_Node_Ptr)malloc(sizeof(Link_Node));
	node->data = (char*)malloc(strlen(data));
	strcpy(node->data,data);
	node->next = NULL;
	return node;
}

//����һ������
Link_Node_Ptr insertNode(Link_Node_Ptr head,Link_Node_Ptr node)
{
	Link_Node_Ptr p = node;
	if(p==NULL)return head;		//��©
	while(p->next!=NULL)p=p->next;
	p->next = head;
	return node;
}

//ɾ��һ������
Link_Node_Ptr deleteNode(Link_Node_Ptr head,Link_Node_Ptr node)
{
	if(head==NULL)return head;
	Link_Node_Ptr p=head;
	Link_Node_Ptr q=p->next;
	
	//ɾ��ͷ�ڵ�
	if(strcmp(p->data,node->data)==0)
	{
		head=p->next;
		free(p);
	}
	else	//ɾ����ͷ�ڵ�
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

//��ȡ�����е�һ���ڵ�
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

//�Ƚ�ǰ���hashֵ�Ƿ�����ͬ����һ���ı�ʾ����ȡ������1��û����ͬ�ķ���0
int hashCompare(int i,Link_Node_Ptr x)
{
	int j;
	for(j=0;j<i;j++)
	{
		if(hashFun(j,(uint8_t *)x->data,strlen(x->data),HASH_TABLE_LEN)==hashFun(i,(uint8_t *)x->data,strlen(x->data),HASH_TABLE_LEN))return 1;
	}
	return 0;
}



