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
const int maxn = 1000005;

ll t, n, a[maxn], ans = -INF, d[maxn], u, v;
ll h[maxn], e[maxn], ne[maxn], tot;
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}


void dfs(int u, int fa) {
	d[u] = a[u];
	for (int i = h[u]; ~i; i = ne[i]) {
		int to = e[i];
		if (to != fa) dfs(to, u), d[u] += max(0ll, d[to]);
	}
	ans = max(d[u], ans);
}

void solve() {
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
		cin >> u >> v, add(u, v), add(v, u);
	dfs(1, -1);
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

