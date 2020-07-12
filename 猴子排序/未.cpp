#include<stdio.h>
int main()
{
	int x,y;
	printf("请输入x的值%d\n",x);
	scanf("%d",&x);
	if(x>0)
	{if(0<x&&x<=10)
	        y=x+3;
	else
	        y=2*x-1;
	}
	else if(-10<=x&&x<0)
		 y=x;
	else
	   y=4-3;
	printf("y的结果是%d\n",y);
}


