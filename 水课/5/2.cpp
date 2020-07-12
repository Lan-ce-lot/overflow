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
ll qsqrt(ll a,ll n,ll mod)
{
	ll temp=a,ans=1;
	for(;n>0;n>>=1)
	{
		
		if(n&1)
		{
			ans=(ans%mod)*(temp%mod)%mod;
			ans%mod;
		}
		temp=(temp*temp)%mod;
	}
	return ans%mod;
}
int main()
{
	ll k,p,n,ans=0;
	cin>>k>>p>>n;
	for(int i=1;i<=k;i++)
	{
		ans+=qsqrt(i,n,p);
	}
	cout<<ans%p<<endl;
	return 0;

}
