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
const int maxn=50005;
int par[maxn],rank[maxn];
string str_Q = "Query";
string str_A = "Add";
string str_S = "Sub";
string str_E = "End";
string str;
int num[maxn],t,n,tree[maxn<<2],case_n=1;
int lowbit(int x)
{
	return x & -x;
}

void add(int x,int v)
{
    while(x <= maxn)
    {
        tree[x] += v;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",case_n++);
        scanf("%d",&n);
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            add(i,num[i]);
        }

        while(cin>>str && str != str_E)
        {
            if(str == str_A)
            {
                int a,b,x;
                scanf("%d%d",&a,&b);
                add(a,b);
            }
            if(str == str_Q)
            {
                int a,b,x;
                scanf("%d%d",&a,&b);
                printf("%d\n",getsum(b) - getsum(a - 1));
            }
            if(str == str_S)
            {
                int a,b,x;
                scanf("%d%d",&a,&b);
                add(a,-b);
            }
        }
    }
    return 0;
}
