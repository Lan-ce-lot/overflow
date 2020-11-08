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
const int maxn = 10005;
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
vector<int> G[maxn];
int w[maxn];
int siz[maxn];
int dp[1005], ans = INF;
void dfs(int u, int f, int d) {
	siz[u] = w[u];
	for (int i = 0; i < G[u].size(); i++) {
		int e = G[u][i];
		if (e != f) {
			dfs(e, u, d + 1);
			siz[u] += siz[e];
		}
	}
	dp[1] += w[u] * d;
}

void do_dp(int u, int f) {
	for (int i = 0; i < G[u].size(); i++) {
		int e = G[u][i];
		if (e != f) {
			dp[e] = dp[u] + siz[1] - siz[e] * 2;
			do_dp(e, u);
		}
	}
	ans = min(ans, dp[u]);
}

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		w[i] = read();
		int a = read(), b = read();
		if (a) G[i].push_back(a), G[a].push_back(i);
		if (b) G[i].push_back(b), G[b].push_back(i);
	}
	dfs(1, 0, 0);
	do_dp(1, 0);
	
	cout << ans << endl;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

