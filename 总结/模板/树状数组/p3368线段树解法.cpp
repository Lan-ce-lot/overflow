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
const int maxn=500005;
int a[maxn];
int ts[maxn << 2],tl[maxn << 2];


void build(int p,int l,int r)
{
	tl[p] = 0;
	if(l == r)
	{
		ts[p] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2,l,mid);
	build(p * 2 + 1,mid + 1,r);
	ts[p] = ts[p * 2] + ts[p * 2 + 1];
	return;
}

void pushdown(int p,int l,int r)
{
    int mid = (l + r) / 2;

    ts[p *2] += tl[p] * (mid - l + 1);
    ts[p * 2 + 1] += tl[p] * (r - mid); 
	tl[p * 2] += tl[p];
    tl[p * 2 + 1] += tl[p];
    tl[p] = 0;
    return;
}

void updata(int p,int l,int r,int x,int y,ll k)
{
	if(l > y || r < x)return;
	if( x <= l && y >= r)
    {
        ts[p] += k * (l - r + 1);
        tl[p] += k;
        return;
    }
    pushdown(p,l,r);
    int mid = (l + r) / 2;
    updata(2 * p, l,mid,x,y,k);
    updata(2 * p + 1,mid + 1,r,x,y,k);
    ts[p] = (ts[p * 2] + ts[p * 2 + 1]);
    return;
}

//error 
ll query(int p,int l,int r,int x,int y) 
{
    if(x > r || y < l)return 0;
    if(x <= l && y >= r)return ts[p];
    pushdown(p,l,r);
    int mid = (l + r) / 2;
    return (query(2 * p,l,mid,x,y)+query(2 * p + 1,mid + 1,r,x,y));
}

int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    while(m--)
    {
        int index,x,y;
        ll k;
        scanf("%d",&index);
        if(index == 1)
        {
            scanf("%d%d%lld",&x,&y,&k);
            updata(1,1,n,x,y,k);
        }
        else
        {
            scanf("%d",&x);
            printf("%lld\n",query(1,1,n,x,x));

        }

    }
    return 0;
}
