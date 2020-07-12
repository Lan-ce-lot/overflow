#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
int main()
{
	int n,m,t;	
	while(~scanf("%d%d",&n,&m))
	{
		t=n;
		if(n==0&&m==0)break;
		int a[100],b[100],c[100]={0};
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				a[j]==b[i]?c[j]=1,t--:i;
		if(t<=0)
			printf("NULL");
		else
			for(int i=0;i<n;i++)
			{
				if(c[i])
				continue;
				printf("%d ",a[i]);
			}	
		printf("\n");
	 } 
	return 0;
}
