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
const int maxn = 1000005;
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
struct node {
	int s, ne, to, m;
	double r;
}G[maxn], G2[maxn];
int h[maxn], tot, h2[maxn], tot2;
void add(int a, int b, int m, double r) {
	G[tot] = {a, h[a], b, m, r}, h[a] = tot++;
}
void add2(int a, int b, int m) {
	G2[tot2] = {a, h2[a], b, m, 0}, h2[a] = tot2++;
}
int dfn[maxn], low[maxn], num, stack[maxn], top;
bool instack[maxn];
int scc[maxn], sc, ind;
void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	stack[++top] = x;
	instack[x] = 1;
	for (int i = h[x]; ~i; i = G[i].ne) {
		int y = G[i].to;
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		} else if (instack[y]) {
			low[x] = min(low[x], low[y]);
		}
	}
	if (dfn[x] == low[x]) {
		++sc;
		while (stack[top] != x) {
			scc[stack[top]] = sc;
			instack[stack[top]] = 0;
			top--;
		}
		scc[x] = sc;
		instack[x] = 0;
		top--;
	}
}
int f[maxn], val[maxn], in[maxn], ans;
void topo() {
	queue<int> q;
	for (int i = 1; i <= sc; i++) {
		if (!in[i]) q.push(i);
		f[i] = -INF;
	}
	f[scc[s]] = val[scc[s]];
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = h2[u]; ~i; i = G2[i].ne) {
			int v = G2[i].to;
			f[v] = max(f[u] + G2[i].m + val[v], f[v]);
			in[v] --;
			if (!in[v]) q.push(v);
		}
	}
	for (int i = 1; i <= sc; i++) ans = max(ans, f[i]);
}
void solve()
{
	memset(h, -1, sizeof h);
	memset(h2, -1, sizeof h2);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		double d;
		cin >> a >> b>> c >> d;
		add(a, b, c, d);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 0; i < m; i++) 
		if (scc[G[i].s] != scc[G[i].to]) {
			add2(scc[G[i].s], scc[G[i].to], G[i].m);
			in[scc[G[i].to]] ++;
		} else {
			while (G[i].m) {
				val[scc[G[i].to]] += G[i].m;
				G[i].m *= G[i].r;
			}
		}
	cin >> s;
	topo();
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

