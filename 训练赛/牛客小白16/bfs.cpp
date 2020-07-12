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
int maze[55][55];
int num1[3500];
int dir[2][2]={{0,1},{1,0}};
int vis[55][55];
int n;
struct node{
	int x,y,vau;
	node(int xx,int yy,int vv)
	{
		x=xx;
		y=yy;
		vau=vv;
	}
};

bool test(int x,int y)
{
	if(x>=n||y>=n)
	{
		return 0;
	}
	return 1;
}

void bfs(int x,int y,int v1)
{
	queue<node> q;
	q.push(node(x,y,v1));
	while(!q.empty())
	{
		node top=q.front();
		q.pop();
		vis[x][y]=1;
		if(top.x==n-1&&top.y==n-1)
		{
			num1[top.vau]++;
			
		}
		for(int i=0;i<2;i++)
		{
			int tx=top.x+dir[0][i];
			int ty=top.y+dir[1][i];
			int tv=top.vau+maze[tx][ty];
			if(test(tx,ty))
			{
				q.push(node(tx,ty,tv));
				vis[tx][ty]=1; 
			}
		}
		
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
	bfs(0,0,maze[0][0]);
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
