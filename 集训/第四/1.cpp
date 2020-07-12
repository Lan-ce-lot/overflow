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
/*int power(int p,int k)
{
	int ans=1,t=1;
	while(k)
	{
		if(t==1)t=p;else t=t*t;
		if(k%2==1)ans=ans*t;
		k>>=1;
	}
	return ans;
}*/

int power(ll a, ll n)
{
    ll ans = 1;
    while(n > 0) {
        if(n&1) {
            ans *= a;
            ans %= 2;
        }
        a *= a%2;
        a %= 2;
        n /= 2;
    }
    return ans%2;
}
/*ll power(ll a,ll b)
{
    ll r=1,base=a;
    while(b!=0)
    {
        if(b%2) r*=base;
        base*=base;
        b>>=1;
    }
    return r;
}*/
int main()

{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",m%power(2,n));
	return 0;

}
