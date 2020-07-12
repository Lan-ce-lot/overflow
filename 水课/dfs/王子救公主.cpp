#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
char mp[105][105];
int m,n;
bool vis[105][105][2];
void dfs(int x,int y,int d)
{
	if(x<0||x>=n||y<0||y>=m||vis[x][y][d]||mp[x][y]=='#')
	{
		return;
	}		
	vis[x][y][d]=true;
	dfs(x-(2-d),y,d);
	dfs(x+(2-d),y,d);
	dfs(x,y-(2-d),d);
	dfs(x,y+(2-d),d);
}

int main()
{
	int x,y;
	bool ans=false;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='w')
			{
				x=i;
				y=j;
			}	
		}
	}
	
	dfs(x,y,0);cout<<"ss";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='g')
			{
				x=i;y=j;cout<<"cc";
			}		
		}
	}	
	dfs(x,y,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		if(vis[i][j][0]&&vis[i][j][1])
		{
			ans=true;cout<<"dd";
		}
	}
	puts(ans?"yes":"no");
	return 0;
}
