#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include<bits/stdc++.h> 
using namespace std;

struct Node
{
	int x;
	int y;
};

int g[600][600];
int hashtable[600][600]={0};
vector<Node> g3;
int n=0;

void bfs(int x3,int y3)
{
	queue<Node> q;
	Node a={x3,y3};
	hashtable[x3][y3]=1;
	q.push(a);
	g3.push_back(a);
	while(!q.empty())
	{
		Node b=q.front();
		q.pop();
		if(b.x+1<=n&&hashtable[b.x+1][b.y]==0&&g[b.x+1][b.y]==0)
		{
			a={b.x+1,b.y};
			g3.push_back(a);
			hashtable[a.x][a.y]=1;
			q.push(a);
		}
		if(b.x-1>=1&&hashtable[b.x-1][b.y]==0&&g[b.x-1][b.y]==0)
		{
			a={b.x-1,b.y};
			g3.push_back(a);
			hashtable[a.x][a.y]=1;
			q.push(a);
		}
		if(b.y+1<=n&&hashtable[b.x][b.y+1]==0&&g[b.x][b.y+1]==0)
		{
			a={b.x,b.y+1};
			g3.push_back(a);
			hashtable[a.x][a.y]=1;
			q.push(a);
		}
		if(b.y-1>=1&&hashtable[b.x][b.y-1]==0&&g[b.x][b.y-1]==0)
		{
			a={b.x,b.y-1};
			g3.push_back(a);
			hashtable[a.x][a.y]=1;
			q.push(a);
		}		
	 }
	 
}


int main()
{
	int x1,y1,x2,y2;
	int temp,min=1000000000;
	scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char c;
			scanf("%c",&c);
			if(c!='0'&&c!='1')
			{
				scanf("%c",&c);
			}
			if(c!='0'&&c!='1')
			{
				scanf("%c",&c);
			}
			g[i][j]=c-'0';
		}
	}
	vector<Node> g1,g2;
	bfs(x1,y1);
	g1=g3;
	g3.clear();
	bfs(x2,y2);
	g2=g3;
	for(int i=0;i<g1.size();i++)
	{
		for(int j=0;j<g2.size();j++)
		{
			int temp=(g1[i].x-g2[j].x)*(g1[i].x-g2[j].x)+(g1[i].y-g2[j].y)*(g1[i].y-g2[j].y);
			if(temp<min)
			{
				cout<<min<<' ';
				min=temp;
			}
		}
	}
	printf("%d",min);
	return 0;
}

