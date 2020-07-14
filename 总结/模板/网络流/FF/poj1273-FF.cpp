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
const int maxn = 205;
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
int t, n, m;

struct edge {
	int to, cap, rev;
};

vector<edge> G[205];
bool vis[maxn];

void add_edge(int from, int to, int cap) {
	G[from].push_back({to, cap, G[to].size()});
	G[to].push_back({from, 0, G[from].size() - 1});
}

int dfs(int v, int t, int f) {
	if (v == t) return f;
	vis[v] = 1;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!vis[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		memset(vis, 0, sizeof vis);
		int f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
}

void solve()
{
	while (~scanf("%d%d", &n, &m)) {
//		G.clear(); 
//		G = vector<edge> ();
		for (int i = 0; i < 205; i++) {
			G[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			int xx, yy, ee;
//			cout << i << endl;
			scanf("%d%d%d", &xx, &yy, &ee);
			add_edge(xx, yy, ee);
//			cout << i << ' ' << n << endl;
		}

		printf("%d\n", max_flow(1, m));
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

