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
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int a[100005];
int a2=0,b0=0,c4=0;
int main()
{
	int n,z,t;
	ll sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&z);
		if(z==2)a2++;
		if(z==0)b0++;
		if(z==4)c4++;
	}
	a[0]=0;
	if(b0+1>a2+c4)
	{
		printf("%lld\n",32*c4+8*a2);
		return 0;
	}
	for(int i=1;i<=n;i+=2,c4--)
	{
	
		if(c4==0)
		{
		t=i;	
		break;	
		}
			a[i]=4;	
	}
	if(c4)
	{
		for(int i=0;c4>0;i++)
		a[n-i]==0?a[n-i]=4,c4--:i;
	}
	for(int i=t;a2>0&&i<=n;a2--,i+=2)
	{
		a[i]==0?a[i]=2:i;
	}
	for(int i=n;a2>0;i--)
	{
		a[i]==0?a[i]=2,a2--:i;
	}
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(a[i]-a[i-1]);
	}
//		for(int i=0;i<=n;i++)
//	{
//		printf("%d",a[i]);
//	}
	printf("%lld\n",sum);
	return 0;
}
