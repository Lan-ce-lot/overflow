#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm> 
#include<queue>
using namespace std;
typedef long long ll;
#define PI 3.1415927
#define M(a) memset(a,0,sizeof(a))
const int INF=0x3f3f3f3f;
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
string M="DLRU";
int vis[30][50];
char mazz[30][50];
struct node{
	int x,y,step;
	string str;
	node(int xx,int yy,string s,int st)
	{
		x=xx;
		y=yy;
		str=s;
		step=st;
	}
};

bool test(int x,int y)
{
	if(x<0||y<0||x>=30||y>=50||vis[x][y]==1||mazz[x][y]=='1')
		return 0;
	return 1;
}

void bfs(int x,int y,string s,int step)
{
	queue<node> q;	
	q.push(node(x,y,s,step));
	while(!q.empty())
	{
		node top=q.front();
		q.pop();
		vis[x][y]=1; 
		if(top.x==29&&top.y==49)
		{
			cout<<top.str<<top.step;
			return;
		}
		for(int i=0;i<4;i++)
		{
			int tx=top.x+dir[i][0];
			int ty=top.y+dir[i][1];
			if(test(tx,ty))
			{
				q.push(node(tx,ty,top.str+M[i],top.step+1));
				vis[tx][ty]=1; 
			}
		}
	}
}

int main()
{
	for(int i=0;i<30;i++)
		scanf("%s",mazz[i]);
	bfs(0,0,"",0);
	return 0;
}
