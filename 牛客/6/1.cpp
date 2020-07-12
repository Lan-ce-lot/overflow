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
char map[1005][1005];
bool vis[1005][1005];
int n,m,ans=0;
void dfs(int x,int y,int z0,int y0)
{
	if(x<0||x>=n||y<0||y>=m||vis[x][y]||map[x][y]=='*'||z0<0||y0<0)
		return;
	vis[x][y]=true;
	if(map[x][y]=='.')ans++;
	map[x][y]='+';
	dfs(x+1,y,z0,y0);
	dfs(x,y-1,z0-1,y0);
	dfs(x-1,y,z0,y0);
	dfs(x,y+1,z0,y0-1);
	vis[x][y]=false;
}
int main()
{
	int x,y,zz,yy;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&x,&y);
	scanf("%d%d",&zz,&yy);
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
	}
	dfs(x-1,y-1,zz,yy);
	printf("%d\n",ans);
}
