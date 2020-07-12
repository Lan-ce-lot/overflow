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
int main()
{
	ll a[100005];
	ll n,q,l,r;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);
		ll ans=0;
		for(int i=l-1;i<r;i++)
		{
			
			ans+=a[i];
			if(ans<0)
			{
				ans=0;
			}
		}
		printf("%lld\n",ans);
	 } 
	return 0;

}
