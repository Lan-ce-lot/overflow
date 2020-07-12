#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <stdlib.h>
#include <list>
#include <map>
#include <utility>
#include <time.h>
#include <set>
#include <bitset>
#include <vector>
#define pi acos(-1.0)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define ms(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
ll qpow(ll x, ll y, ll mod)
{
    ll s=1;
    while(y)
    {
        if(y&1)
            s=s*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return s;
}
int n,m,k;
int val[500005];
int cnt[500005];
int ans[500005];
int a[10005];
int Left,Right;
int sum=0;
int block;
struct node
{
    int l,r;
    int id;
} p[100005];
int cmp(node a,node b)
{
    if((a.l/block)==(b.l/block))
        return a.r<b.r;
    return a.l<b.l;
}
int add(int x)//把x位置的数字加入进来
{
    cnt[val[x]]++;//cnt[i]为当前区间值为i的前缀有多少个
    sum+=cnt[val[x]^k];
}

int remove(int x)//把x位置的数字移出去
{
    cnt[val[x]]--;
    sum-=cnt[val[x]^k];
}

int main()
{
    cin >> n;
//    scanf("%d%d%d",&n,&m,&k);
    block=(int)sqrt(n);
    for(int i=1; i<=n; i++)
        scanf("%d",&val[i]),val[i]^=val[i-1];
//    for(int i=0; i<m; i++)
//        scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
//    sort(p,p+m,cmp);
    p[0].l = 1, p[0].r = n, p[0].id = 0;
    k = 0;
    Left=1;
    Right=0;
    cnt[0]=1;
//    for(int i=0; i<m; i++)
//    {
        while (Left<p[0].l)
        {
            remove(Left-1);
            Left++;
        }
        while (Left>p[0].l)
        {
            Left--;
            add(Left-1);
        }
        while (Right<p[0].r)
        {
            Right++;
            add(Right);
        }
        while (Right>p[0].r)
        {
            remove(Right);
            Right--;
        }
        ans[p[0].id]=sum;
        cout << sum << endl;
//    }
//    for(int i=0; i<m; i++)
//        printf("%d\n",ans[i]);

    return 0;
}

