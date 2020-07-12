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

ll n,ans,x_1,x_2,x_3;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
    	scanf("%lld%lld%lld",&x_1,&x_2,&x_3);
    	printf("%lld\n",(x_1+x_2+x_3)/2);
	}
    return 0;
}
