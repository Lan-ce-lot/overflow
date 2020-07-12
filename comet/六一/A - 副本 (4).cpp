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
int a[505];
ll ans=0;
ll f(ll k,ll n,ll i)
{

	if(k>n-1)
	{
		ans+=(n-1)*a[i];cout<<ans<<endl;
		return k>=0?f(k-n+1,n,i+1):ans; 
	}
	else if(k<=n-1)
	{
		ans+=k*a[i];cout<<ans<<i<<endl;
		return ans; 
	}
}
int main()
{
	ll n,k;
	ll ans=0;
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]); 
	}
	sort(a,a+n,greater<int>());

	cout<<f(2*k,n,0)<<endl;
//	system("pause");
	return 0;

}
