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
int n,m,ans=0;
char mp[105][105];
bool vis[105][105];
void dfs(int x,int y)
{
	if(x<0||x>=n||y<0||y>=m||vis[x][y]||mp[x][y]=='.')return;
	vis[x][y]=true;
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x-1,y);
	dfs(x,y+1);
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
			if(!vis[i][j]&&mp[i][j]=='#')
			{
				ans++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",ans);
//	system("pause");
	return 0;
}
