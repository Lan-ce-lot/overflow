#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<vector> 
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
char map[105][105];
int n,m,x,y;
void dfs(int x,int y,int con)
{
	if(x<0||x>=n||y<0||y>=m||con>3)
	{
		return;
	 } 
	 map[x][y]='#';
	 dfs(x+2,y+1,con+1);
	 dfs(x+2,y-1,con+1);
	 dfs(x-2,y+1,con+1);
	 dfs(x-2,y-1,con+1);
	 dfs(x+1,y+2,con+1);
	 dfs(x+1,y-2,con+1);
	 dfs(x-1,y+2,con+1);
	 dfs(x-1,y-2,con+1);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			map[i][j]='.';
	dfs(x-1,y-1,0);
	for(int i=0;i<n;i++)
		printf("%s\n",map[i]);
	return 0;
}
