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
bool f(ll t)
{
	if(t/10==0&&t%10!=6)
	{
		return false;
	}
	
	return t%10==6?true:f(t/10);
}
int main()
{
	ll x,y,ans=0;
	scanf("%lld%lld",&x,&y);
	for(int i=x;i<=y;i++)
	{
		f(i)?ans++:i;
	}
	printf("%lld",ans);
	return 0;
}
