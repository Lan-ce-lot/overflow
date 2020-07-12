#include<bits/stdc++.h>
//p=p->next，就让p指向了下一个结点的数据。(*p).next
//p->next 是 p 所指向的结构的 next 成员；
using namespace std;
struct Student
{
	char cName[20],sex[10],major[20];					
	int iNumber,age;						
	struct Student* pNext;					
};

int iCount;								

struct Student* Create()
{
	struct Student* pHead=NULL;			
	struct Student* pEnd,*pNew;
	iCount=0;							
	pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));
	printf("please first enter Name ,then Number,sex,age,major\n");
	scanf("%s",&pNew->cName);
	scanf("%d",&pNew->iNumber);
	scanf("%s",&pNew->sex);
	scanf("%d",&pNew->age);
	scanf("%s",&pNew->major);
	while(pNew->iNumber!=0)
	{
		iCount++;
		if(iCount==1)
		{
			pNew->pNext=pHead;		
			pEnd=pNew;				
			pHead=pNew;					
		}
		else
		{
			pNew->pNext=NULL;			
			pEnd->pNext=pNew;			
			pEnd=pNew;				
		}
		pNew=(struct Student*)malloc(sizeof(struct Student));	
		scanf("%s",&pNew->cName);
		scanf("%d",&pNew->iNumber);
		scanf("%s",&pNew->sex);
		scanf("%d",&pNew->age);
		scanf("%s",&pNew->major);
	}
	free(pNew);						
	return pHead;
}

void Print(struct Student* pHead)
{
	Student *pTemp;					
	int iIndex=1;						

	printf("----the List has %d members:----\n",iCount);		
//	printf("\n");						
	pTemp=pHead;						

	while(pTemp!=NULL)
	{
		printf("the NO%d member is:\n",iIndex);
		printf("the name is: %s\n",pTemp->cName);	
		printf("the number is: %d\n",pTemp->iNumber);
		printf("the sex is: %s\n",pTemp->sex);
		printf("the age is: %d\n",pTemp->age);
		printf("the major is: %s\n",pTemp->major);		
		printf("--------------------------------\n");					
		pTemp=pTemp->pNext;				
		iIndex++;							
	}
}

void del1(struct Student* pHead)
{
	
	printf("--------------------------------\n");
	printf("请输入要删除的学号：");
	int _number;
	Student *p;
	
	scanf("%d", &_number);
	for (p=pHead; p->pNext!= NULL; p = p->pNext)
	{
		if ((p->pNext)->iNumber==_number)
		{
			Student* q = p->pNext;
			p->pNext = (p->pNext)->pNext;
			delete q;
			printf("已删除学号为：%d的学生信息。\n", _number);
			iCount--;
			break;
		}
	}
 } 
 
 void del2(struct Student* pHead)
{
	
	printf("--------------------------------\n");
	printf("请输入要删除的专业：");
	char _major[20];
	Student *p;
	scanf("%s", _major);
	for (p=pHead; p->pNext!= NULL; )
	{
		if (strcmp((p->pNext)->major, _major) == 0)
		{
			Student* q = p->pNext;
			p->pNext = (p->pNext)->pNext;
			delete q;
			printf("已删除专业为：%s的学生信息。\n", _major); 
			iCount--;
			continue;
		}
		p = p->pNext;
	}
 } 
int main()
{
	struct Student* pHead;				
	pHead=Create();																
	Print(pHead);
	puts("删除的方式：\n1.学号\n2.专业\n--------------------------------");
	int an;
	scanf("%d",&an);
	an==1?del1(pHead):del2(pHead);
	Print(pHead);						
	return 0;							
}
