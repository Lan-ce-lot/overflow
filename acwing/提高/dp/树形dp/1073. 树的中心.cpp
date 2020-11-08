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
#define x first
#define y second
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;
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
int d1[maxn], d2[maxn], from[maxn], up[maxn];
bool is_left[maxn];
vector<PII> G[maxn];

int dfs_d(int u, int f) {
	d1[u] = d2[u] = -INF;
	for (int i = 0; i < G[u].size(); i++) {
		PII tem = G[u][i];
		if (f == tem.x) continue;
		
		int d = dfs_d(tem.x, u) + tem.y;
		if (d >= d1[u]) {
			d2[u] = d1[u], d1[u] = d;
			from[u] = tem.x;
		} else if (d > d2[u]) d2[u] = d;
		

	}		
	if (d1[u] == -INF) {
		d1[u] = d2[u] = 0;
		is_left[u] = 1;
	}
	return d1[u];
}

void dfs_u(int u, int f) {
	for (int i = 0; i < G[u].size(); i++) {
		PII tem = G[u][i];
		if (f == tem.x) {
			continue;
		}
		if (from[u] == tem.x) {
			up[tem.x] = max(up[u], d2[u]) + tem.y;
		} else {
			up[tem.x] = max(up[u], d1[u]) + tem.y;
		}
		dfs_u(tem.x, u);
	}
	
}


void solve()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a = read(), b = read(), c = read();
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	dfs_d(1, -1);
	
	dfs_u(1, -1);
	int res = d1[1];
	for (int i = 2; i <= n; i++) {
		if (is_left[i]) res = min(res, up[i]);
		else res = min(res, max(d1[i], up[i]));
	}
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

