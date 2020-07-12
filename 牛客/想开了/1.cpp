#include <bits/stdc++.h>
#define N 21
#define M 10000000
#define Nxt (now>>(x-1)&1)
using namespace std;
int n,m,k,ans,cnt;
int a[N][N],v[N][N];
int rt[N][N],ch[M][2],sum[M];
void ins(int &p,int now,int x=31)
{
    if(!p)p=++cnt;sum[p]++;
    if(x)ins(ch[p][Nxt],now,x-1);
}
int ask(int p,int now,int x=30)
{
    if(x<0)return 0;int k=now>>x&1,ok=sum[ch[p][!k]];
    return ok>0?ask(ch[p][!k],now,x-1)+(1<<x):ask(ch[p][k],now,x-1);
}
void dfs1(int x,int y,int now)
{
    if(x<1||y<1)return ;
    if(v[x][y]) return ans=max(ans,ask(rt[x][y],now)),void();
    dfs1(x-1,y,now^a[x][y]);dfs1(x,y-1,now^a[x][y]);
}
void dfs(int x,int y,int now)
{
    if(x>n||y>n) return ;
    if(v[x][y]) return ins(rt[x][y],now^a[x][y]),void();
    dfs(x+1,y,now^a[x][y]);dfs(x,y+1,now^a[x][y]);
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=n;j++)
    		cin>>a[i][j];
    for(int i=1;i<=n;i++)
    	v[i][n-i+1]=1;
    dfs(1,1,k);dfs1(n,n,0);
    cout<<ans<<endl;
    return 0;
}
