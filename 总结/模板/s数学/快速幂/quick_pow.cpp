#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=1005;
ll q_power(ll x,ll n,ll mod)
{
	
	ll res=1;
	while(n>0)
	{
		if(n&1)
			res=res*x%mod;
		x=x*x%mod;
		n>>=1;	
	}
	return res;
 } 
 
//ตÝน้ 
//ll q_power(ll x,ll n,ll mod)
//{
//	if(n==0)
//		return 1;
//	ll res=q_power(x*x%mod,n/2,mod);
//	if(n&1)
//		res=res*x%mod;
//	return res;
//}

int a[maxn];
int main()
{
	cout<<q_power(2,4,1000);
    
    return 0;
}
