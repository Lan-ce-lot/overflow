#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
ll f(ll x)
{	
	ll ret=3,ans=1;
	while(x>0)
	{	
		if(x&1)
			ans=(ans*ret)%998244353;
		ret=(ret*ret)%998244353;	
		x>>=1;
	}
	return ans;
}

int main()
{
	ll n,ans;
	scanf("%lld",&n); 
	printf("%lld",f(n)%998244353);
	return 0;

}
