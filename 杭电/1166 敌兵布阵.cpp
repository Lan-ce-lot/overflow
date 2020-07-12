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
int par[maxn],rank[maxn];
string str_Q = "Query";
string str_A = "Add";
string str_S = "Sub";
string str_E = "End";
string str;
int num[maxn],t,n,tree[maxn<<2],case_n=1;

void build(int p,int l,int r)
{
    if(l == r)
    {
        tree[p] = num[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(p *2,l,mid);
    build(p * 2 + 1,mid + 1,r);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

int query(int p,int l,int r,int x,int y)//询问通常是维护值(sum)
{
    if(x <= l && r <= y)return tree[p];
    int mid = (l + r) / 2 ,sum = 0;
    if(x <= mid)
    {
        sum+=query(p * 2,l,mid,x,y);
    }
    if(y>mid)
    {
        sum+=query(p * 2 + 1,mid + 1,r,x,y);
    }
    return sum;
}

void add(int p,int l,int r,int node,int x)
{
    if(l == r)
    {
    	tree[p] += x;
		return;
	}
    int mid = (l + r) / 2;
    if(node <= mid)
        add(p * 2,l,mid,node,x);
    else
        add(p * 2 + 1,mid + 1,r,node,x);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];

}


int main()
{
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",case_n++);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        build(1,1,n);

        while(cin>>str && str != str_E)
        {
            if(str == str_A)
            {
                int a,b,x;
                scanf("%d%d",&a,&b);
                add(1,1,n,a,b);
            }
            if(str == str_Q)
            {
                int a,b,x;
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,1,n,a,b));
            }
            if(str == str_S)
            {
                int a,b,x;
                scanf("%d%d",&a,&b);
                add(1,1,n,a,-b);
            }
        }
    }
    return 0;
}
