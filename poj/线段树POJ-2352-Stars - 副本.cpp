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
int tree[maxn<<2];
int x[maxn];
void build(int p,int l,int r,int x)
{

    if(l == r)
    {
        tree[p] ++ ;
        return;
    }
    int mid = (l + r) / 2;
    if(mid >= x)build(p * 2,l,mid,x);
    else build(2 * p + 1,mid + 1,r,x);
    tree[p] = tree[2 * p] + tree[2 * p + 1];

}

int find(int p,int l,int r,int x,int y)
{
    if(l <= x && y >= r)return tree[p];
    int mid = (l + r) / 2;
    if(y <= mid)return find(2 * p,l,mid,x,y);
    if(x>mid)return find(2 * p,mid + 1,r,x,y);
    return find(2 * p,l,mid,x,mid)+find(2 * p + 1,mid+1,r,mid + 1,y);

}

int a[maxn],n,y;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof(tree));
        memset(a,0,sizeof(a));
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d%d",&x[i],&y);
            build(1,0,maxn,x[i]);
            a[find(1,0,maxn,0,x[i])-1]++;
        }
        for(int i = 0;i < n;i ++ )
        {

            printf("%d\n",a[i]);
        }
    }

    return 0;
}
