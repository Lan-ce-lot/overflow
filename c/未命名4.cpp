#include<bits/stdc++.h> 

using namespace std;
char map11[55][55];
int map1[55][55];
int vis[55][55];
int n,ans=100000000;

struct node
{
	int x;
	int y; 
};
vector<node> s1,s2,s3;
vector<node> island1,island2;
bool te(int x,int y)
{
	if(x<0||x>=n||y<0||y>=n||vis[x][y]==1||map1[x][y]==1)
		return false;
	else
		return true;	
}
void bfs(int a,int b)
{
	
	queue<node> q;
	node zz={a,b};
	vis[a][b]=1;
	s3.push_back(zz);
	q.push(zz);
	while(!q.empty())
	{
		node top=q.front();
		q.pop();
		if(te(top.x+1,top.y))
		{
			zz={top.x+1,top.y};
			s3.push_back(zz);
			q.push(zz);
			vis[zz.x][zz.y]=1;
		}
		if(te(top.x,top.y+1))
		{
			zz={top.x,top.y+1};
			s3.push_back(zz);
			q.push(zz);
			vis[zz.x][zz.y]=1;
		}
		if(te(top.x-1,top.y))
		{
			zz={top.x-1,top.y};
			s3.push_back(zz);
			q.push(zz);
			vis[zz.x][zz.y]=1;
		}
		if(te(top.x,top.y-1))
		{
			zz={top.x,top.y-1};
			s3.push_back(zz);
			q.push(zz);
			vis[zz.x][zz.y]=1;
		}
	}
	
}
int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
	for(int i=0;i<n;i++)
	{
		scanf("%s",map11[i]);	
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			map1[i][j]=map11[i][j]-'0';
		}
	}
	int l1,l2;
	bfs(x1-1,y1-1);
	s1=s3;
	l1=s1.size();
	s3.clear();
	
	bfs(x2-1,y2-1);
	s2=s3;	
	l2=s2.size();
	for(int i=0;i<l1;i++)
	{
		for(int j=0;j<l2;j++)
		{
			ans=min(ans,(s1[i].x-s2[j].x)*(s1[i].x-s2[j].x)+(s1[i].y-s2[j].y)*(s1[i].y-s2[j].y));
		}
	}
	printf("%d\n",ans);
	return 0;
}
