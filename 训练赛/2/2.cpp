#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef unsigned long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
struct node{
	ll a,b,c,p;
		
}a1[1005];
bool cmp(node a,node b)
{
	ll x1=a.c*(b.a+b.b+b.c);
	ll x2=b.c*(a.a+a.b+a.c);
	return x1==x2?a.p<b.p:x1>x2;
}
int main()
{	
	int n;
	while(~scanf("%d",&n))
	{

		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&a1[i].a,&a1[i].b,&a1[i].c);
			a1[i].p=i+1;
		}
		sort(a1,a1+n,cmp);
		
		for(int i=0;i<n;i++)
		{
			i==n-1?printf("%lld\n",a1[i].p):printf("%lld ",a1[i].p);
		}
	 } 
	
	
//	system("pause");
	return 0;
}
