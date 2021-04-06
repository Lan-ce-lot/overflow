#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,time;
} p; //x,y存坐标，time存当前的时间 
int m,x,y,t,nx,ny,time1[305][305],c[305][305]; //time1数组存这个格子流星最早到达的时间，c存是否到过这个格子，数组开大点！！！！ 
int b1[4]= {0,0,1,-1},b2[4]= {1,-1,0,0};
queue<node>q;
int main()
{
	cin>>m;
	for(int i=0; i<=302; i++)
		for(int j=0; j<=302; j++)
			time1[i][j]=-1; //先都赋初值为-1 
	for(int i=1; i<=m; i++)
	{
		cin>>x>>y>>t;
		if(t<time1[x][y]||time1[x][y]==-1) //这颗流星到达的时间必须小于前面流星或焦土到达的时间，或者还暂时没有流星及焦土 
		time1[x][y]=t; 
		for(int i=0; i<4; i++)
		{
			nx=x+b1[i],ny=y+b2[i];
			if(nx>=0&&ny>=0&&(time1[nx][ny]==-1||t<time1[nx][ny]))
				time1[nx][ny]=t;  //枚举焦土 
		}
	}
	p.x=0,p.y=0,p.time=0,c[0][0]=1;
	q.push(p);  
	while(!q.empty())
	{
		p=q.front();q.pop();
		for(int i=0; i<4; i++)
		{
			nx=p.x+b1[i],ny=p.y+b2[i];
			if(nx>=0&&ny>=0&&c[nx][ny]==0&&(time1[nx][ny]==-1||p.time+1<time1[nx][ny])) //没有流星到过或者bessie到这个格子的时候流星还没有到达 
			{
				node txt;
				txt.x=nx,txt.y=ny,txt.time=p.time+1,c[nx][ny]=1; //扩展节点 
				q.push(txt);
				if(time1[nx][ny]==-1) //判断当前的格子是否安全 
				{
					cout<<txt.time<<endl; //输出答案 
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl; //到不了安全的格子就输出-1 
	return 0;
}
