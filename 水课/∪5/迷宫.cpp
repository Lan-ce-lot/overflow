#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
#include<queue>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int vis[15][15],maze[15][15],x1[4]={1,-1,0,0},yl[4]={0,0,1,-1};
int good=0,step=0,ans=INF;
bool test(int x,int y)
{
	if(x<0||y<0||x>=10||y>=10||vis[x][y]==1)
		return false;
	return true;
	
}
void dfs(int a,int b,int step,int good)
{
	if(!test(a,b))
	{
		return;
	}
	if(step>ans)
	{
		return;
	}
	if(a==0&&b==9&&good==10)
	{
		ans=min(step,ans);
	}
	vis[a][b]=1;
	for(int i=0;i<4;i++)
	{
		maze[a][b]==1?dfs(a+x1[i],b+yl[i],step+1,good+1):dfs(a+x1[i],b+yl[i],step+1,good);
	}
	vis[a][b]=0;
	
}
int main()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>maze[i][j];
		}
	}
	
	dfs(0,0,0,0);	
	cout<<ans;
	return 0;
}
