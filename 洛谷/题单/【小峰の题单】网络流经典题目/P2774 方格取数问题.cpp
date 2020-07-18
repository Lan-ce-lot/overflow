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
int t, n, m, s;
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


//==============================================


int ma[105][105];
int side1[10005], side2[10005],cnt1, cnt2;
vector<PII> s1;
vector<PII> s2;
bool test(int i, int j) {
	if (abs(s1[i].first - s2[j].first) == 1 && abs(s1[i].second - s2[j].second) == 0) return 1;
	if (abs(s1[i].first - s2[j].first) == 0 && abs(s1[i].second - s2[j].second) == 1) return 1;
	return 0;
}
void solve()
{
	ll sum = 0;
	m = read(), n = read();
	for (int i = 1; i <= m; i++) {
	 	for (int j = 1; j <= n; j++) {
	 		ma[i][j] = read();
	 		sum += ma[i][j];
	 		if ((i + j) & 1) {
//	 			side[(i - 1) * m + j]
				s1.push_back(PII(i, j));
	 			side1[cnt1++] = ma[i][j];	
			} else {
				s2.push_back(PII(i, j));
				side2[cnt2++] = ma[i][j];
			}
		}
	} 
	s = 0, t = n * m + 1;
	for (int i = 0; i < cnt1; i++) {
		add_edge(s, i + 1, side1[i]);
	}
	for (int i = 0; i < cnt2; i++) {
		add_edge(i + 1 + cnt1, t, side2[i]);
	}

	for (int i = 0; i < cnt1; i++) {
		for (int j = 0; j < cnt2; j++) {
			if (test(i, j)) {
				add_edge(i + 1, j + cnt1 + 1, INF);
			}
			
		}
	}
	cout << sum - max_flow(s, t) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

