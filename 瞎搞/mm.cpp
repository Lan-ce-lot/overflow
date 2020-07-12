#include <stdio.h>

int  swap(int *p1,int *p2);//实现交换

int main()
{
	int a,b;
	int *point1,*point2;

	printf("input two number:\n");
	scanf("%d %d",&a,&b);

     point1=&a;
     point2=&b;

	if(a<b)
	{
     int swap=(*point1,*point2);//实现交换
	}
    printf("max=%d,min=%d\n",a,b);
}
int swap(int *p1,int*p2)
{
	int p;

	p=*p1;//p等于a
	*p1=*p2;
	*p2=p;
}
