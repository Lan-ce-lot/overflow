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
bool cmp(int a,int b)
{
	return a>b;
}
int f1(int a)
{
	int b[4],sum=0,n=1000;
	for(int i=0;i<4;i++)
	{
		b[i]=a%10;
		a/=10;
	}
	sort(b,b+4,cmp);
	for(int i=0;i<4;i++)
	{
		sum+=b[i]*n;
		n/=10;
	}
	return sum;
}
int f2(int a)
{
	int b[4],sum=0,n=1000;
	for(int i=0;i<4;i++)
	{
		b[i]=a%10;
		a/=10;
	}
	sort(b,b+4);
	for(int i=0;i<4;i++)
	{
		sum+=b[i]*n;
		n/=10;
	}
	return sum;
}
int main()
{
	int n,t;
	scanf("%d",&n); 
	while(t!=6174)
	{
		printf("%04d - %04d = %04d\n",f1(n),f2(n),f1(n)-f2(n));
		if(f1(n)-f2(n)==0)break;
		t=n=f1(n)-f2(n);	
	}
	return 0;
}
