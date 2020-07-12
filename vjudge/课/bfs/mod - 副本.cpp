#include <iostream>
#include <queue>
#include <string.h>
//优先队列，因为距离最短，不一定时间最短，所以用优先队列，优先处理时间短的点
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int s;
int n,m;  //行，列
char map[200][200];
bool st[200][200];
struct node{
	int x,y,step;
}S,T,Node;
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};
int minans=1<<30;

struct cmp{
	bool operator() (node a,node b){
		return a.step > b.step;
	}
};

bool judge(int x,int y){
	if(x< 0 || x>=n || y<0 || y>=m) return false;
	if(map[x][y] == '#') return false;
	if(st[x][y] == true)  return false;
	return true;
}

int bfs(){
	priority_queue<node,vector<node>,cmp> q;
	q.push(S);
	st[S.x][S.y] =true;
	while(!q.empty())
	{
		node tp=q.top();
		cout << tp.x << tp.y << tp.step << endl;
		q.pop();
		if(tp.x == T.x && tp.y == T.y)
		{
			return tp.step;
		}
		for(int i=0;i<4;i++)
		{
			int newX=tp.x+fx[i];
			int newY=tp.y+fy[i];
			if(judge(newX,newY))
			{
				Node.x=newX;
				Node.y=newY;
				Node.step=tp.step+1;
				if(map[newX][newY] == 'x')
				Node.step+=1;
				q.push(Node);
				st[newX][newY] = true;
			}
		}
	}
	return -1;
}
int main(int argc, char** argv) {
	cin >> s;
	while(s--)
	{
		cin >> n >> m;
		memset(map,'\0',sizeof(map));
		memset(st,false,sizeof(st));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> map[i][j];
				if(map[i][j] == 'r')
				{
					S.x=i;
					S.y=j;
					S.step=0;
				}
				if( map[i][j] == 'a')
				{
					T.x=i;
					T.y=j;
				}
			}
		}
        int t=bfs();
        if(t==-1)
        cout << "Impossible" << endl;
        else
        cout << t << endl;
	}
	return 0;
}
