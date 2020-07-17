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
const int maxn = 1e4+5;
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
	for (int &i = iter[v]; i < G[v].size(); i++) { // 当前弧优化 
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
int life1[maxn];
int life2[maxn];
string str1[1005];
string str2[1005];
//==============================================
void solve()
{
//	cin >> m >> n;
	cin >> n >> m;
	int xu1 = 0;
	int xu2 = 0;
	map<string, int> M;
	M["J"]   = 1;// 2 3
	M["W"]   = 2;// 4 5
	M["HK"]  = 3;// 2 5
	M["YYY"] = 4;// 1 3
	M["E"]   = 5;// 1 4
	
	for (int i = 1; i <= n; i++) {
		cin >> str1[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> str2[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> life1[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> life2[i];
	}
	for (int i = 1; i <= n; i++) {
		string tem1 = str1[i], tem2 = str2[i];
		if (tem1[0] == 'Y') {
			xu1 ++;
		}
		if (tem2[0] == 'Y') {
			xu2 ++;
		}
	}
	S = 0, T = n * 2 + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			string tem1 = str1[i], tem2 = str2[j];
			if (tem1[0] == 'J' && (tem2[0] == 'W' || tem2[0] == 'H')) add_edge(i, j + n, 1);
			if (tem1[0] == 'W' && (tem2[0] == 'Y' || tem2[0] == 'E')) add_edge(i, j + n, 1);
			if (tem1[0] == 'H' && (tem2[0] == 'W' || tem2[0] == 'E')) add_edge(i, j + n, 1);
			if (tem1[0] == 'Y' && (tem2[0] == 'J' || tem2[0] == 'H')) add_edge(i, j + n, 1);
			if (tem1[0] == 'E' && (tem2[0] == 'J' || tem2[0] == 'Y')) add_edge(i, j + n, 1);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		string tem1 = str1[i], tem2 = str2[i];
		add_edge(S, i, life1[i] + (tem1[0] == 'J' ? xu1 : 0)), add_edge(i + n, T, life2[i] + (tem2[0] == 'J' ? xu1 : 0));
	}
	
	cout<<min(max_flow(S, T), m * 1ll);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

