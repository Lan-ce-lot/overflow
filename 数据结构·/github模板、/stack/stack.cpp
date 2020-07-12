#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10000 
typedef struct SNode *Stack;
#define ElementType int
struct SNode{
	ElementType Data[MAX_N];
	int top;
}a;

void push(Stack PtrS,int item)
{
	if(PtrS->top==MAX_N-1)
	{
		printf("¶ÑÕ»Âú");
		 
	}
	else
	{
		PtrS->Data[++(PtrS->top)] = item;
	}
}

ElementType pop(Stack PtrS)
{
	if(PtrS->top==-1)
	{
		printf("empty");
		return -1;
		
	}
	else
	{
		return (PtrS->Data[(PtrS->top)--]);
	}
}
int main()
{
	push(&a,1);
	push(&a,12);
	push(&a,1);
	cout<<pop(&a)<<endl;
	cout<<pop(&a)<<endl;
	cout<<pop(&a)<<endl;
	cout<<pop(&a)<<endl;
	cout<<pop(&a)<<endl;
//	system("pause");
	return 0;
}
