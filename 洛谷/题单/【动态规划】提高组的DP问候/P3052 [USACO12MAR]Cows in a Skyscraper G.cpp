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
int t, n, m, ni[maxn], f[1 << 19], g[1 << 19];
int vis[maxn];
bool dfs(int u, int num) {
	for (int i = 1; i <= u && i <= num; i++) {
		if (vis[i] + ni[u] <= m) {
			vis[i] += ni[u];
			if (u == n) return 1;
			if (dfs(u + 1, num)) return 1;
			vis[i] -= ni[u];
		}
	}
	return 0;
}
void solve() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		ni[i] = read();
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		if (dfs(1, i)) {
			cout << i << endl;return;
		}
	}
}

int main() {

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

