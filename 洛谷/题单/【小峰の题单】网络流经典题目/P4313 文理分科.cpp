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
const int maxn = 1e6+5;
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
int t, n, m, S, T;
//==============================================
struct edge {
	int to; ll cap; int rev; 
};

vector<edge> G[maxn];
int level[maxn];
int iter[maxn];

void add_edge(int from, int to, ll cap) {
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size() - 1});
}

void bfs(int s) {
	memset(level, -1, sizeof level);
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front();
		que.pop();
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

ll dfs(int v, int t, int f) {
	if (v == t) return f;
	for (int &i = iter[v]; i < G[v].size(); i++) { // ��ǰ���Ż� 
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			ll d = dfs(e.to, t, min(f * 1ll, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

ll max_flow(int s, int t) {
	ll flow = 0;
	for (;;) {
		bfs(s);
		if (level[t] < 0) return flow;
		memset(iter, 0, sizeof iter);
		ll f;
		while ((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}


//==============================================
int ma[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int get(int i, int j) {
	return (i - 1) * m + j;
}

void solve()
{
	n = read(), m = read();
	S =  0, T = n * m + 1;
	int al = T;
	int sum = 0, art, sci, id;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			art = read(), id = get(i, j);
			sum += art;
			add_edge(S, id, art);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sci = read(), id = get(i, j);
			sum += sci;
			add_edge(id, T, sci);
		}
	}
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			art = read(), id = get(i, j);
			al++;
			sum += art;
			add_edge(S, al, art);
			add_edge(al, id, INF);
			for (int k = 0; k < 4; k++) {
				if (i + dir[k][0] >= 1 && i + dir[k][0] <= n && j + dir[k][1] >= 1 && j + dir[k][1] <= m) {
					add_edge(al, get(i + dir[k][0], j + dir[k][1]), INF);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			art = read(), id = get(i, j);
			al++;
			sum += art;
			add_edge(al, T, art);
			add_edge(id, al, INF);
			for (int k = 0; k < 4; k++) {
				if (i + dir[k][0] >= 1 && i + dir[k][0] <= n && j + dir[k][1] >= 1 && j + dir[k][1] <= m) {
					add_edge(get(i + dir[k][0], j + dir[k][1]), al, INF);
				}
			}
		}
	}
	cout << sum - max_flow(S, T) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

