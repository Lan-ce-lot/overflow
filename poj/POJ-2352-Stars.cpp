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
const int maxn=32005;
int tree_a[maxn];
int lowbit(int x)
{
    return x & (-x);

}

void updata(int x)
{
    while(x <= maxn)
    {
        tree_a[x] ++;
        x += lowbit(x);
    }
}

int query(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += tree_a[x];
        x -= lowbit(x);
    }
    return sum;
}
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[maxn],n,x,y;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(tree_a,0,sizeof(tree_a));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[query( x)] ++ ;
            updata(x);
        }
        for(int i=0;i<n;i++)
        {

            printf("%d\n",a[i]);
        }
    }

    return 0;
}
