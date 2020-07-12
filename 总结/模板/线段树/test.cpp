#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define maxn (int)1e5 + 6   						//可根据需要修改 !!!!
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int num[maxn],N,M,mod;
int tree[maxn];
struct node
{
    ll sum;
    ll lazyadd,lazymul;
}A[maxn << 2];

void build(int p,int l,int r)
{

    A[p].lazyadd = 0;
    A[p].lazymul = 1;
    if(l == r)A[p].sum = num[l];
    else
    {
        int mid = (l + r) / 2;
        build(p * 2,l,mid);
        build(p * 2 + 1,mid + 1,r);
        A[p].sum = A[2 * p].sum + A[2 * p + 1].sum;
    }
    A[p].sum %= mod;
    return ;
}

void pushdown(int p,int l,int r)
{
    int mid = (l + r) / 2;
    A[p * 2].sum = (A[p * 2].sum * A[p].lazymul + A[p].lazyadd * (mid - l + 1)) % mod;
    A[p * 2 + 1].sum = (A[p * 2 + 1].sum * A[p].lazymul + A[p].lazyadd * (r - mid)) % mod;

    A[p * 2].lazymul = (A[p * 2].lazymul * A[p].lazymul) % mod;
    A[p * 2 + 1].lazymul = (A[p * 2 + 1].lazymul *A[p].lazymul) % mod;
    A[p * 2].lazyadd = (A[p * 2].lazyadd * A[p].lazymul + A[p].lazyadd) % mod;
    A[p * 2 + 1].lazyadd = (A[p * 2 + 1].lazyadd * A[p].lazymul + A[p].lazyadd) % mod;

    A[p].lazymul = 1;
    A[p].lazyadd = 0;
    return ;
}
//5 5 100000
//1 2 3 4 5
void mul(int p,int l,int r,int x,int y,ll k)
{
    if(x > r || l > y)return;
    if(x <= l && r <= y)
    {
        A[p].sum *= k;
        A[p].lazymul *= k;
        A[p].lazyadd *= k;
        A[p].sum %= mod;
        A[p].lazymul %= mod;
        A[p].lazyadd %= mod;
        return ;
    }
    pushdown(p,l,r);
    int mid = (l + r) / 2;
    mul(2 * p,l,mid,x,y,k);
    mul(2 * p + 1,mid + 1,r,x,y,k);
    A[p].sum = (A[p * 2].sum + A[p * 2 + 1].sum) % mod;
    return;
}

void add(int p,int l,int r,int x,int y,ll k)
{
    if(x > r || l > y)return;
    if(x <= l && r <= y)
    {
        A[p].sum += k * (r - l + 1);
        A[p].lazyadd += k;
        A[p].sum %= mod;
        A[p].lazyadd %= mod;
        return;
    }
    pushdown(p,l,r);
    int mid = (l + r) / 2;
    add(2* p,l,mid,x,y,k);
    add(2 * p + 1,mid + 1,r,x,y,k);
    A[p].sum = (A[2 * p].sum + A[2 * p + 1].sum) % mod;
    return;
}

ll query(int p,int l,int r,int x,int y)
{
    if(x > r|| l > y)return 0;
    if(x <= l && r <= y)return A[p].sum;
    pushdown(p,l,r);
    int mid = (l + r) / 2;
    return (query(2 * p,l,mid,x,y) + query(2 * p + 1,mid + 1,r,x,y)) % mod;

}
int main()
{
    scanf("%d%d%d",&N,&M,&mod);
    for(int i = 1;i <= N;i++)
        scanf("%d",&num[i]);
    build(1,1,N);
    while(M--)
    {
        int temp,x,y;
        ll k;
        scanf("%d",&temp);
        if(temp == 1)
        {
            scanf("%d%d%lld",&x,&y,&k);
            mul(1,1,N,x,y,k);
        }
        if(temp == 2)
        {
            scanf("%d%d%lld",&x,&y,&k);
            add(1,1,N,x,y,k);

        }
        if(temp == 3)
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,1,N,x,y));
        }

    }
    return 0;
}
