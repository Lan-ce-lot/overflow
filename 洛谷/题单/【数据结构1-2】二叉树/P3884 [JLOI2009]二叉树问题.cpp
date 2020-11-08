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
const int maxn = 20005;
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
int t, n;
int depth[maxn], fa[maxn][16], q[maxn];
int h[maxn], ne[maxn], e[maxn], idx = 1;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int ans1 = 0, ans0 = 0; 
void bfs(int root) {
	memset(depth, INF, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	int hh = 0, tt = 0;
	q[0] = root;
	int tem = 0;
	while (hh <= tt) {

		int t = q[hh++];
		for (int i = h[t]; i; i = ne[i]) {

			int j = e[i];
			if (depth[j] > depth[t] + 1) {
				depth[j] = depth[t] + 1;
				q[++tt] = j;
				fa[j][0] = t;
				for (int k = 1; k <= 15; k ++) 
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
			}
		}
	}
} 
void dfs(int k, int f) {
	depth[k] = depth[f] + 1;
	q[k] = depth[k];
	ans0 = max(ans0, depth[k]);
	fa[k][0] = f;
	for (int i = 1; (1 << i) <= depth[k]; i++)
		fa[k][i] = fa[fa[k][i - 1]][i - 1];
	for (int i = h[k]; i; i = ne[i]) 
		if (e[i] != f) dfs(e[i], k);
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 13; k >= 0; k--) 
		if (depth[fa[a][k]] >= depth[b]) a = fa[a][k]; 
	if (a == b) return a;
	for (int k = 13; k >= 0; k--)
		if (fa[a][k] != fa[b][k]) a = fa[a][k], b = fa[b][k];
	return fa[a][0];  
}

int kuang[maxn];
void solve()
{
	n = read();
	idx = 1;
	memset(h, 0, sizeof h);
	for (int i = 1; i <= n - 1; i ++) {
		int x = read(), y = read();
		add(x, y);
		add(y, x);
	}
	bfs(1);
//	dfs(1, 0);
	int x = read(), y = read();
	for (int i = 1; i <= n; i++) {
		if (depth[i] != INF)
		ans0 = max(ans0, depth[i]);
	}
	for (int i = 1; i <= n; i++) {
		kuang[depth[i]]++;
	}
	for (int i = 1; i <= ans0; i++) ans1 = max(ans1, kuang[i]);
//	ans1 = *max_element(kuang, kuang + ans0 + 1);
	cout << ans0 << '\n' << ans1 << '\n';
	int tem = lca(x, y);
	cout << (depth[x]-depth[tem])*2+(depth[y]-depth[tem]) << '\n';
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

