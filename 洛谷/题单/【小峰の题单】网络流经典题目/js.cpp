
#include<iostream>
#include<iomanip>
#include<cmath>
#include<map> 
#include<string>
#include<vector>
#include<set> 
#include<queue> 
#include<algorithm>
#include<string.h>


#define MAXN 5050
#define INF 0x3f3f3f3f
#define P pair<int,int>

using namespace std;
struct edge
{
	int to, cap, cost, rev;
};
vector<edge> G[MAXN];
int h[MAXN];
int dist[MAXN], prevv[MAXN], preve[MAXN]; //dist������̾���
										//�����·���У�prevv[i]��ʾi��ǰ��ڵ㣬preve[i]��ʾ�ڽӱ��еľ���λ��  
int n, m, s, t;//n������\m����\sԴ��\t��� 

int maxFlow, minCost; //��fΪINF maxflow��Ч��Ϊ������� 


void addedge(int from, int to, int cap, int cost)
{
	edge temp1 = { to, cap, cost, (int)G[to].size() };
	G[from].push_back(temp1);
	edge temp2 = { from, 0, -cost, (int)G[from].size()-1 };
	G[to].push_back(temp2);
}
void MCMF(int s, int t, int f) //��fΪINFʱ��������������С���� 
{
	fill(h , h +2 + n, 0);  //�����Ŵ�1��ʼ ��1-n�� 
	while (f > 0)
	{
		//Dijkstra�㷨ʵ��
		priority_queue<P, vector<P>, greater<P> > D;
		memset(dist, INF, sizeof dist);
		dist[s] = 0; D.push(P(0, s));
		while (!D.empty())
		{
			P now = D.top(); D.pop();
			if (dist[now.second] < now.first) continue;
			int v = now.second;
			for (int i = 0; i<(int)G[v].size(); ++i)
			{
				edge &e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
				{
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					D.push(P(dist[e.to], e.to));
				}
			}
		}
		if (dist[t] == INF) break;
		for (int i = 0; i <= n+1; ++i) h[i] += dist[i];
		int d = f;
		for (int v = t; v != s; v = prevv[v])
			d = min(d, G[prevv[v]][preve[v]].cap);
		f -= d; maxFlow += d;
		minCost += d * h[t];
		for (int v = t; v != s; v = prevv[v])
		{
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
}
int num[105];
int sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		sum+=num[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			addedge(i,(i+1)%n,INF,1);
			addedge((i+1)%n,i,INF,1);
		}
		else
		{
			addedge(i,(i+1),INF,1);
			addedge((i+1),i,INF,1);
		}
		if(num[i]-sum>0)
		{
			addedge(0,i,num[i]-sum,0);
		}
		else if(num[i]-sum<0)
		{
			addedge(i,n+1,sum-num[i],0);
		}
	}
	MCMF(0,n+1,INF);
	cout<<minCost<<endl;
	return 0;
}
