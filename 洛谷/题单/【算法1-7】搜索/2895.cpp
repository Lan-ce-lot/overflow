#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,time;
} p; //x,y�����꣬time�浱ǰ��ʱ�� 
int m,x,y,t,nx,ny,time1[305][305],c[305][305]; //time1�������������������絽���ʱ�䣬c���Ƿ񵽹�������ӣ����鿪��㣡������ 
int b1[4]= {0,0,1,-1},b2[4]= {1,-1,0,0};
queue<node>q;
int main()
{
	cin>>m;
	for(int i=0; i<=302; i++)
		for(int j=0; j<=302; j++)
			time1[i][j]=-1; //�ȶ�����ֵΪ-1 
	for(int i=1; i<=m; i++)
	{
		cin>>x>>y>>t;
		if(t<time1[x][y]||time1[x][y]==-1) //������ǵ����ʱ�����С��ǰ�����ǻ��������ʱ�䣬���߻���ʱû�����Ǽ����� 
		time1[x][y]=t; 
		for(int i=0; i<4; i++)
		{
			nx=x+b1[i],ny=y+b2[i];
			if(nx>=0&&ny>=0&&(time1[nx][ny]==-1||t<time1[nx][ny]))
				time1[nx][ny]=t;  //ö�ٽ��� 
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
			if(nx>=0&&ny>=0&&c[nx][ny]==0&&(time1[nx][ny]==-1||p.time+1<time1[nx][ny])) //û�����ǵ�������bessie��������ӵ�ʱ�����ǻ�û�е��� 
			{
				node txt;
				txt.x=nx,txt.y=ny,txt.time=p.time+1,c[nx][ny]=1; //��չ�ڵ� 
				q.push(txt);
				if(time1[nx][ny]==-1) //�жϵ�ǰ�ĸ����Ƿ�ȫ 
				{
					cout<<txt.time<<endl; //����� 
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl; //�����˰�ȫ�ĸ��Ӿ����-1 
	return 0;
}
