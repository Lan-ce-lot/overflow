#include<stdio.h>

int fruit(int days);

int main()
{
	int days,result;

	printf("input a days that you want to seached:\n");
	scanf("%d",&days);

	result=fruit(days);

	if(result==0)
	{
	printf("输入结果错误，请重新输入\n");
	}
	else
		printf("还剩余%d个桃子\n",result);
}
int fruit(int days)
{
	int i;
	if(days<1)
	{
		return 0;
	}
	if(10==days)
	{
	     i=1;
	}
	else
		i=(fruit(days+1)+1)*2;
	return i;
}
