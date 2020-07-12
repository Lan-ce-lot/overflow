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
struct node{
	int num[4],step;
}first,last;
int vis[11][11][11][11];
void bfs()
{
	int i;
	node a,next;
	queue<node> q;
	a=first;
	a.step=0;
	q.push(a);
	memset(vis,0,sizeof vis);
	vis[a.num[0]][a.num[1]][a.num[2]][a.num[3]]=1;
	while(!q.empty())
	{
		a=q.front();
		q.pop();
//		bfs exit
		if(a.num[0]==last.num[0]&&a.num[1]==last.num[1]&&a.num[2]==last.num[2])
		{
			printf("%d\n",a.step);
			return ;
			
		}
		for(i=0;i<4;i++)
		{
			next=a;
			next.num[i]++;
			if(next.num[i]==10)
			{
				next.num[i]=1;
			}
			if(!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]])
			{
				vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]=1;
				next.step++;
				q.push(next);
			}
		}
		for(i=0;i<4;i++)
		{
			next=a;
			next.num[i]--;
			if(next.num[i]==0)
			{
				next.num[i]=9;
			}
			if(!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]])
			{
				vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]=1;
				next.step++;
				q.push(next);
			}
		}
		for (i=0;i<3;i++)
		{
			next=a;
			next.num[i]=a.num[i+1];
			next.num[i+1]=a.num[i];
			if(!vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]])
			{
				vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]]=1;
				next.step++;
				q.push(next);
			}
		}
	}
}

int main()
{
	int i,j,t;
	char s1[10],s2[10];
	scanf("%s%s",s1,s2);
	for(i=0;i<4;i++)
	{
		first.num[i]=s1[i]-'0';
		last.num[i]=s2[i]-'0';
	 } 
	 bfs();
	return 0;
}
