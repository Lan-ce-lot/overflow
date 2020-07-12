#include<bits/stdc++.h> 

using namespace std;
char map11[55][55];
int map1[55][55],ans=500000000;
int vis[55][55],bj[55][55];
int n,island[550][2][2],idex=0,c1,c2;
int dfs(int x,int y,int a)
{

	if(x<0||y<0||x>=n||y>=n)
		return 0;
	if(map1[x][y]==0&&vis[x][y]==0)
	{
		vis[x][y]=1;
		dfs(x+1,y,a);
		dfs(x,y+1,a);
		dfs(x-1,y,a);
		dfs(x,y-1,a);
			bj[x][y]=a;
			island[idex][0][a-1]=x;
			island[idex][1][a-1]=y;
			idex++;
	}
}

int main()
{
	int x1,x2,y1,y2;
	scanf("%d",&n);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=0;i<n;i++)
	{
		scanf("%s",map11[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			map1[i][j]=map11[i][j]-'0';
		}
	}
	dfs(x1-1,y1-1,1);
	if(bj[x2-1][y2-1]==1)
	{
		puts("0");
		return 0;
	}
	c1=idex;
	idex=0;
	dfs(x2-1,y2-1,2);
	c2=idex;
	for(int i=0;i<c1;i++)
	{
		for(int j=0;j<c2;j++)
		{
			ans=min(((island[i][0][0]-island[j][0][1])*(island[i][0][0]-island[j][0][1])+(island[i][1][0]-island[j][1][1])*(island[i][1][0]-island[j][1][1])),ans);
		}
	 } 
	printf("%d\n",ans); 
	return 0;
}
