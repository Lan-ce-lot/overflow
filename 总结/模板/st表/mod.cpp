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
const int maxn=1e7+5;
int d[maxn][25];
int mn[maxn];
int n,m;
int a[maxn];
void rmq_init()
{
    for(int i=1;i<=n;i++)
        d[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
      for(int i=1;i+(1<<j)-1<=n;i++)
        d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
    for(int len=1;len<=n;++len){
        int k=0;
        while((1<<(k+1))<=len)
            k++;
        mn[len]=k;
    }
}

int rmq(int L,int R)
{
    int k=mn[R-L+1];
    return max(d[L][k],d[R-(1<<k)+1][k]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}
	rmq_init();
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		
		printf("%d\n",rmq(x,y));
	}
    return 0;
}
