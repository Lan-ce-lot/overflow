#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
using namespace std;
char mp[15][15];
bool vis[15][15];
int n,m,ans=0,x,y;
void dfs(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||vis[x][y]||mp[x][y]=='#')return;
	if(mp[x][y]=='e')
	{
		ans++;
		return;
	}
	vis[x][y]=true;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
	vis[x][y]=false;
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
			if(mp[i][j]=='s')
			{
				x=i;
				y=j;
			}
		}
	}
	dfs(x,y);
	printf("%d",ans);
	return 0;
}
