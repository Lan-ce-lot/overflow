/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 3e2 + 10;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		f = -1;
		ch = getchar();
	}
    while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
    return x * f;
}
ll sum[maxn];
// ===================================================================
int t, n, m, s, q;
int num[maxn];
// first->shortest dis, second->node
typedef pair<int, int> PII;

struct edge {
	int to, cap, cost, rev;
};

vector<edge> G[maxn];				
int h[maxn];						// 顶点的势
int dis[maxn];						// 最短距离
int prevv[maxn], preve[maxn];		// 最短路中的前驱节点和对应的边

vector<int> res;
// 加一条从from到to容量为cap费用为cost的边
void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back((edge){to, cap, cost, G[to].size()});
	G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}


ll min_cost_flow(int s, int t, ll f = INF) {
	ll ans = 0, flow = 0;
	fill(h, h + t + 1, 0);
	fill(prevv, prevv + t + 1, 0);
	fill(preve, preve + t + 1, 0);
	while (f > 0) {
		priority_queue<PII, vector<PII>, greater<PII> > que;
		fill(dis,dis + t + 1, INF);
		dis[s] = 0;
		que.push(PII(0, s));
		while (!que.empty()) {
			PII p = que.top();
			que.pop();
			int v = p.second;
			if (dis[v] < p.first) continue;
			for (int i = 0; i < G[v].size(); i++) {
				edge &e = G[v][i];
				if (e.cap > 0 && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]) {
					dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;
					preve[e.to] = i;
					que.push(PII(dis[e.to], e.to));
				}
			}
		}
		if (dis[t] == INF) {
			return -1;
//			break;
		}
		for (int v = 0; v <= t + 1; v++) h[v] += dis[v];
		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		flow += d;
		ans += d * h[t];
		res.push_back(h[t] * d);
		for (int v = t; v != s; v = prevv[v]) {
			G[prevv[v]][preve[v]].cap -= d;
			G[v][G[prevv[v]][preve[v]].rev].cap += d;
		}
	}
	return ans;
}

void init() {
	res.clear();
	for (int i = 0; i < maxn; i++) {
		G[i].clear();
	}
}
// ========================================================
//void solve()
//{
//	init();
//	int n1, sum1 = 0, ave;
//	n1 = read();
//	s = 0, t = n1 + 1, n = n1 + 2;
//	for (int i = 1; i <= n1; i++) {
//		num[i] = read();
//		sum1 += num[i];
//	}
//	ave = sum1 / n1;
//	for (int i = 1; i <= n1; i++) {
//		if (num[i] > ave) {
//			add_edge(s, i, num[i] - ave, 0);
//		} else {
//			add_edge(i, t, ave - num[i], 0);
//		}
//	}
//
//	for (int i = 2; i <= n1; i++) {
//		add_edge(i - 1, i, INF, 1);
//		add_edge(i, i - 1, INF, 1);
//	}
//	add_edge(1, n1, INF, 1);
//	add_edge(n1, 1, INF, 1);
//	cout << min_cost_flow(s, t) << endl;
//}
void solve() {
	int n1, sum1 = 0;
	scanf("%d",&n1);
	s = 0, t = n1 + 1, n = n1 + 2;
	for(int i=1;i<=n1;i++)
	{
		scanf("%d",&num[i]);
		sum1+=num[i];
	}
	sum1/=n1;
	int tem = 0;
	for(int i=1;i<=n1;i++)
	{
		if(i==n1)
		{
			add_edge(i,(i+1)%n1,INF,1);
			add_edge((i+1)%n1,i,INF,1);
		}
		else
		{
			add_edge(i,(i+1),INF,1);
			add_edge((i+1),i,INF,1);
		}
		if(num[i]-sum1>0)
		{
			add_edge(0,i,num[i]-sum1,0);
			tem += num[i]-sum1;
		}
		else if(num[i]-sum1<0)
		{
			add_edge(i,n1+1,sum1-num[i],0);
		}
	}
	
	cout << min_cost_flow(s, t, tem) << endl;
//	MCMF(0,n+1,INF);
}


int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

