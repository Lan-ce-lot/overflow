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
int k[5],p[5],ans=0,n,m;
ll spow(int a,int b)
{
	ll ans=1,ret=a;
	while(b>0)
	{
		if(b&1)
			ans*=ret;
		ret*=ret;
		b>>=1;
	}
	return ans;
}
void dfs(int x,ll s)
{
	if(x==n)
	{
		if(s==0)
			ans++;
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		dfs(x+1,s+k[x]*spow(i,p[x]));
	}	
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%d",&k[i],&p[i]);
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
