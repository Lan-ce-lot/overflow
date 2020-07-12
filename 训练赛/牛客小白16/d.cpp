#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
#include<set> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int maze[55][55];
int num1[3500];
int n;
bool test(int x,int y)
{
	if(x>=n||y>=n)
		return 0;
	return 1;
}

void dfs(int x,int y,int ans)
{
	if(x==n-1&&y==n-1)
	{
		num1[ans]++;
		return;
	}
	if(test(x,y))
	{
		dfs(x+1,y,ans+maze[x+1][y]);
		dfs(x,y+1,ans+maze[x][y+1]);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		scanf("%d",&maze[i][j]);
		
	}
	dfs(0,0,maze[0][0]);
	int ans=0;
	for(int i=0;i<3500;i++)
	{
		if(num1[i])
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
