/*************************************************************************
 > File Name: Dlist.c
 > Author:  jinshaohui
 > Mail:    jinshaohui789@163.com
 > Time:    18-10-07
 > Desc:
 ************************************************************************/
#include<stdio.h>
#include<bits/stdc++.h>
typedef struct DlistNode          //˫��������ÿһ���ڵ�
{
	struct DlistNode *prev;   //�ڵ�ǰ��ָ��
	struct DlistNode *next;   //�ڵ����ָ��
	int    data;              //����
}stDlistNode;

typedef struct Dlisthead          //������������
{
	int size;                 //������
	stDlistNode *head;        //ͷָ��
	stDlistNode *tail;        //β��ָ��
}stDlistHead;
