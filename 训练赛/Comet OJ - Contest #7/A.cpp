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

int a[maxn];
int main()
{
	ll n,l,r,max_gcd=0,min_gcd=0,max_lcm=0,min_lcm=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l>>r;
		if(l==r)
		{
			cout<<r<<' '<<r<<' '<<r<<' '<<r<<endl;
		}
		else
		{
		cout<<r*(r-1)<<' '<<l<<' '<<r<<' '<<1<<endl;
		}
	
	}
    return 0;
}
