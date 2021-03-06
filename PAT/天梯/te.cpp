#include<stdio.h>
#include<math.h>
#define N 100005
int main()
{
	int a[N]={0},b[N]={0},check[N]={0},rs1[N]={0},rs2[N]={0};
	int num,n,t,i;
	int l1=0,l2=0;
	scanf("%d %d",&num,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		scanf(" %d %d",&a[t],&b[t]);
	}
	while(num!=-1)
	{
		if(!check[abs(a[num])])
		{
			check[abs(a[num])]=1;
			rs1[l1++]=num;
		}
		else
		{
			rs2[l2++]=num;
		}
		num=b[num];
	}
	for(i=0;i<l1-1;i++)
	{
		num=rs1[i];
		printf("%05d %d %05d\n",num,a[num],rs1[i+1]);
	}
	num=rs1[i];
	printf("%05d %d -1\n",num,a[num]);
	
	if(l2)
	{
		for(i=0;i<l2-1;i++)
		{
			num=rs2[i];
			printf("%05d %d %05d\n",num,a[num],rs2[i+1]);
		}
		num=rs2[i];
		printf("%05d %d -1\n",num,a[num]);
	}
} 
