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
int t, n;
int a[maxn];
int h[maxn], e[maxn], ne[maxn], tot = 1;

int dp[10005][2];
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}

int ans = 0;
void dfs(int u, int fa) {
	
	
//	debug(1);
//debug(h[u]);
	dp[u][1] = a[u];
	for (int i = h[u]; i; i = ne[i]) {
		int to = e[i];
		
		if (to == fa) {
			continue;
		}
		dfs(to, u);
		dp[u][0] += max(dp[to][1], dp[to][0]);
		dp[u][1] += dp[to][0];
	}
}
bool is_root[maxn];
void solve()
{
	// 哈哈哈哈哈
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	memset(h, 0, sizeof h);
	for (int i = 0; i < n - 1; i++) {
		int aa = read(), bb = read();
		add(bb, aa);
		is_root[aa] = 1;
	}
	int root = 1;
	while (is_root[root]) {
		root++;
	}
//	debug(root);
	dfs(root, 0);
//	debug(dp[root][1]);
//	for (int i = 1; i <= 7; i++) cout << dp[i][0] << ' ' << dp[i][1] << endl;
	cout << max(dp[root][0], dp[root][1]) << endl;
	
	
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

