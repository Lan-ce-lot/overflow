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
const int maxn=1e5+5;

ll num[maxn],n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lld",&num[i]);
    ll p=0,q=0;
    for(int i=1;i<n;i++)
    {
        ll c=num[i]-num[i-1];
        if(c<0)
            p+=c;
        else
            q+=c;
    }
    ll ans1=max(p,q),ans2=abs(q-p)+1;//为会少一个数，所以要加一；
    cout<<ans1<<endl<<ans2;
    return 0;
}
