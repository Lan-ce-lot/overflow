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
char mp[1005][1005]; 
bool vis[1005][1005];
int n,m,ans=0,t;
void dfs(int x,int y)
{	
	if(x<0||x>=n||y<0||y>=m||vis[x][y]||mp[x][y]=='.')return;
	if(mp[x][y]=='#')t++;
	vis[x][y]=true;
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x+1,y);
 } 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dfs(i,j);
			ans=max(ans,t);
			t=0;
		}
	}
	printf("%d",ans);
	return 0;
}
