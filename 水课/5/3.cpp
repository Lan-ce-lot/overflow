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
int bu[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int vis[2001][2001];int n,xx,yy,a,b;
struct no{
	int x,y,step;
};
bool test(int a,int b)
{
	if(vis[a][b]==1||a<0||a>=xx||b<0||b>=yy)
	{
		return 0;
	}
	return 1;
}
int bfs(int a,int b)
{
	queue<no> q;
	no zz={a,b,0};
	vis[a][b]=1;
	q.push(zz);
	while(!q.empty())
	{
		no top=q.front();
		q.pop();
		if(top.x==xx-1&&top.y==yy-1)
		{
			return top.step;
		}
		for(int i=0;i<8;i++)
		{
			if(test(top.x+bu[i][0],top.y+bu[i][1]))
			{
				zz={top.x+bu[i][0],top.y+bu[i][1],top.step+1};
				q.push(zz);		
			}
		}
	}
	return -1;
}
int main()
{

	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&xx,&yy,&a,&b);
		if(xx<=7&&yy<=7)
		{
			cout<<bfs(0,0)<<endl;
			continue;
		}
		if(a<=2*b&&b<=2*b)
		{
			cout<<(a+b)/3+(a+b)%3<<endl;continue;
		}
		if(2*a<b)
		{
			cout<<a+(b-2*a)/2+(b-2*a)%4<<endl;continue;
		}
		if(2*b<a)
		{
			cout<<b+(a-2*b)/2+(a-2*b)%4<<endl;continue;
		}	
	}
	return 0;
}
