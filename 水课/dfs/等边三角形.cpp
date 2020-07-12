#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int n,ai[10005],ans,sum=0; 
bool vis[10005];
void dfs(int a,int b,int c,int cnt)
{
	if(vis[cnt]||cnt>n||sum<3*a||sum<3*b||sum<3*c)return;//
	vis[cnt]=true;
	dfs(a+ai[cnt],b,c,cnt+1);
	dfs(a,b+ai[cnt],c,cnt+1);
	dfs(a,b,c+ai[cnt],cnt+1);
	vis[cnt]=false;
	if(cnt==n&&a==b&&b==c)
	{
		ans=1;
		return;
	}
}
int main()
{

	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ai[i]);sum+=ai[i];
	}
	dfs(0,0,0,0);	
	puts(ans?"yes":"no");
}
