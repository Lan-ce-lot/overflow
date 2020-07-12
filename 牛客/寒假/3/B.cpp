#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define mp(x,y) make_pair(x,y)
#define r(x) read(x)
#define rrr(x,y,z) read(x);read(y);read(z)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pt;
const int N=1e6+5;
const int INF=0x7fffffff;
const int mod=1e9+7;
const double eps=1e-8;
const double pi=acos(-1);
LL n,m;
char s[N];
LL f[N];
LL sum[N];
template<class T>
inline void read(T &x)
{
    char c; x=1;
    while((c=getchar())<'0'||c>'9') if(c=='-') x=-1;
    T res=c-'0';
    while((c=getchar())>='0'&&c<='9') res=res*10+c-'0';
    x*=res;
}
int main()
{
    r(n); scanf("%s",s+1);
    int cnt=0;
    FOR(i,1,n){
        if(s[i]=='1') f[++cnt]=i;
    }
    FOR(i,1,cnt){
        sum[i]=sum[i-1]+f[i];
        cout<<sum[i]<<endl;
        }
    LL ans=0;
    FOR(i,1,cnt){
        cout<<ans<<endl;
        ans=(ans+sum[cnt]-sum[i]-(cnt-i)*f[i]%mod+mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
