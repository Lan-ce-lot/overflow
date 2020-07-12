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
int main()
{
	ll n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
	if(m%(n+1)==0)
	{
		puts("You are loser");
		
	}
	else if(n>m)
		for(int i=m%(n+1);i<=n;i++)
			i==n?printf("%d\n",i):printf("%d ",i);
	else cout<<m%(n+1)<<endl;
	}
	return 0;
}
