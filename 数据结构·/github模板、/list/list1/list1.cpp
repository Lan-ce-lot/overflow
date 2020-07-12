/*************************************************************************
 > File Name: Dlist.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-07
 > Desc:
 ************************************************************************/
#include<stdio.h>
#include <stdbool.h>
#include ".Dlist.h"



void dlist_init(stDlistHead *dlist)		//�����ʼ��
{
	dlist->size = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
	return;
}

void dlist_destory(stDlistHead *dlist)		//ɾ������
{
	stDlistNode *pNode = NULL;

	while(dlist->size > 0)
	{
		pNode = dlist->head;
		dlist->head = dlist->head->next;
		free(pNode);
		dlist->size--;
	}

	memset(dlist,0,sizeof(stDlistHead));

	return;
}

int dlist_insert_head(stDlistHead *dlist,stDlistNode *pNode,int data)		//����ͷ��㣬���������������Ľڵ㣬����
{
   if(pNode == NULL)		//��ֻ����һ������ʱ
   {
	    pNode = (stDlistNode *)malloc(sizeof(stDlistNode));		//�½��ڵ㣬Ϊ�ڵ����ռ䣨malloc����������Ҫ#include<malloc.h>��
	    if (pNode == NULL)
	    {
		    return -1;
	    }
    }

    pNode->data = data;
	pNode->prev = NULL;
	pNode->next = NULL;

	if (dlist->size == 0)		//���������Ϊ0��������ǰ�޽ڵ㣬
	{
		dlist->head = pNode;
		dlist->tail = pNode;
	}
	else                           //����������нڵ㣬�����²���ڵ�Ϊͷ�ڵ�
	{
		pNode->next = dlist->head;
		dlist->head->prev = pNode;
		dlist->head = pNode;
	}

	dlist->size++;		//ÿ�ɹ�����һ�Σ�������+1
	return 0;
}

stDlistNode * dlist_remove_tail(stDlistHead *dlist)		//ɾ��β���ڵ�,������ɾ���ڵ�
{
	stDlistNode *pNode = NULL;

	if(dlist->size == 0)
	{
		return NULL;
	}

    pNode = dlist->tail;
	if(dlist->size > 1)
	{
		dlist->tail = dlist->tail->prev;
		dlist->tail->next = NULL;
	}
	else
	{
		dlist->head = NULL;
		dlist->tail = NULL;
	}
	dlist->size--;
	return pNode;
}

void dlist_remove_node(stDlistHead * dlist,stDlistNode *pNode) 		//ɾ��ָ���ڵ�
{
	if ((dlist == NULL)||(pNode == NULL))
	{
		return;
	}

	if (dlist->head == pNode)
	{
		dlist->head = dlist->head->next;
	}
	else if (dlist->tail == pNode)
	{
		dlist->tail = pNode->prev;

		dlist->tail->next = NULL;
	}
	else
	{
		pNode->prev->next = pNode->next;
		pNode->next->prev = pNode->prev;
	}
	dlist->size--;
	pNode->prev = NULL;
	pNode->next = NULL;

	if (dlist->size == 0)
	{
		memset(dlist,0,sizeof(stDlistHead)); 		//��dlistռ���ڴ�������ֵ��Ϊ0��Ҳ�������head,tailָ������
	}

	return;
}
stDlistNode * dlist_search(stDlistHead * dlist,int data) 		//����ֵ�����ڵ㣬������
{
	stDlistNode *pNode = dlist->head;
	while(pNode != NULL)
	{
		if (pNode->data == data)
		{
			return pNode;
		}
		pNode = pNode->next;

    }
	return NULL;
}

void dlist_dump(stDlistHead *dlist)		//��ʾ�����е�����
{
	int no = 0;
	stDlistNode *pNode = dlist->head;
	while(pNode != NULL)
	{
		printf("\r\n [%d] = %d",no++,pNode->data);
		pNode = pNode->next;		//��pNode����һ���ڵ㸳ֵ��pNode���ƽ�ѭ��
	}

	return;
}


void Lru_dlist(stDlistHead *dlist,int data) 		//LRU���������ʹ�ã�������̭�㷨
{
	stDlistNode *pNode = NULL;

	pNode = dlist_search(dlist,data);
	if (pNode != NULL) 				//������������ҵ����ֵ����ɾ���������ֵ�Ľڵ㣬֮�������ڵ����ͷ��
	{
		dlist_remove_node(dlist,pNode);
	}
	else if(dlist->size >= 4)			//û���������ҵ����������ȴ���4�����������ɾ��β���ڵ㣬�������ݷ���ͷ��
	{
		pNode = dlist_remove_tail(dlist);

	}

	dlist_insert_head(dlist ,pNode,data);

	return;
}

int main()
{
	stDlistHead dlist = {0};
    stDlistNode * pNode = NULL;

	dlist_init(&dlist);

	printf("\r\n inset 1,2,3");
	dlist_insert_head(&dlist,NULL,1);
	dlist_insert_head(&dlist,NULL,2);
	dlist_insert_head(&dlist,NULL,3);

	dlist_dump(&dlist);

	pNode = dlist_remove_tail(&dlist);
	if(pNode != NULL)
	{
		printf("\r\n remove %d",pNode->data);
	}
	dlist_insert_head(&dlist,pNode,4);
	dlist_dump(&dlist);

    Lru_dlist(&dlist,5);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,6);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,7);
	dlist_dump(&dlist);
    Lru_dlist(&dlist,5);
	dlist_dump(&dlist);



	while(dlist.size > 0)
	{
	    pNode = dlist_remove_tail(&dlist);
	    if(pNode != NULL)
	    {
		    printf("\r\n remove %d",pNode->data);
	    	free (pNode);
    	}
	}

	return 0;
}
