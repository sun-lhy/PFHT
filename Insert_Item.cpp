  
#include "hash_1.h"
#include "hashFunc.h"


/*
void bubble_sort(int a[], int n)
{
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
	{
		for (i = 0; i < n - 1 - j; i++)
		{
			if(a[i] > a[i + 1])
			{
				temp=a[i]; 
				a[i]=a[i+1]; 
				a[i+1]=temp;
			}
		}
	}

}
*/


Hash_Header_Ptr  Insert_Item(Hash_Header_Ptr  Hash_Table,Link_Node_Ptr  node)
{
	Hash_Header_Ptr header=(Hash_Header_Ptr)malloc(sizeof(Hash_Header));
	Link_Node_Ptr node_1=(Link_Node_Ptr)malloc(sizeof(Link_Node));
	//Link_Node_Ptr  Y;
	Link_Node_Ptr  x;
	Insert_link(header,node);
	char s[] = {1,1,1};
	for(int m=1;m<=3;m++)
	{
	
		int num[3]={additiveHash((uint8_t *)s, sizeof(s), 200),bernstein((uint8_t *)s, sizeof(s), 200),hashcode((uint8_t *)s, sizeof(s), 200)};
		int flag=0;
		for (int i = 0; i < 3; i++)
		{
		  for (int j = i + 1; j < 3; j++)
		  {
            // 如果发现相同元素就输出
            if (num[i] == num[j])
            {
                flag = 1;
                printf("num[%d] = num[%d] = %d\n", i, j, num[i]);
            }
			else
				printf("不存在相同元素\n");
		  }
		}


	return   Hash_Table;
	}	
}


void main()
{
	Hash_Header_Ptr Hash_Table=(Hash_Header_Ptr)malloc(sizeof(Hash_Header));
	Link_Node_Ptr node=(Link_Node_Ptr)malloc(sizeof(Link_Node));
