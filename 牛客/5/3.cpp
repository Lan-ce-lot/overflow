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
int n,m;
bool vis[505][505];
char map[505][505];
int fx[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
void dfs(int x,int y,int t)
{
	int t1=t;
	if(x<0||x>=m||y<0)
	{
		puts("-1");
		return;
	}
	if(y>=n)
	{
		printf("%d\n",x+1);
		return;
	}
	if(map[y][x]=='\\')
	{
		if(t&1)
		{
			t1=t1+4+1;
			t1%=4;
		}
		else
		{
			t1=t1+4-1;
			t1%=4;
		}
	}
	if(map[y][x]=='/')
	{
		if(!(t&1))
		{
			t1=t1+4+1;
			t1%=4;
		}
		else
		{
			t1=t1+4-1;
			t1%=4;
		}
	}
	dfs(x+fx[t1][1],y+fx[t1][0],t1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	scanf("%s",map[i]);

	for(int i=0;i<m;i++)
	dfs(i,0,0);
//	system("pause");
	return 0;
}
