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
char s[10][10]; 
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool vis[10][10];
bool f;
bool in(int x,int y)
{
	return 0<=x&&x<10&&0<=y&&y<9;
}
void dfs(int x,int y)
{
	vis[x][y]=true;
	if(f){
		return;
	}
	if(s[x][y]=='T')
	{
		f=true;
		return;
	}
	for(int i=0;i<8;i++)
	{
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(in(tx,ty)&&s[tx][ty]!='#'&&!vis[tx][ty])
		{
			dfs(tx,ty);
		}
	}
}
int main()
{
	int x,y;
	for(int i=0;i<10;i++)
	{
		scanf("%s",s[i]);
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(s[i][j]=='S')
			{
				x=i;y=j;
			}
		}
	}
	dfs(x,y);
	puts(f?"Yes":"No");	
	return 0;
}
