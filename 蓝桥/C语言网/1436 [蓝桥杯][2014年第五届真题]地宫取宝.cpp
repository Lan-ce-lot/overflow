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
int t, n, m, k;
int maze[1005][1005];
ll ans = 0;
ll dp[50][50][15][15];
int dir[2][2] = {1, 0, 0, 1};
ll c[1005][1005];
ll dfs(int x, int y, int con, int max) {
	if (dp[x][y][con][max + 1] != -1) {
		return dp[x][y][con][max + 1];
	}
	if (x == n && y == m) {
		if (con == k) {
			return dp[x][y][con][max + 1] = 1;
		} else if (con == k - 1 && max < maze[x][y]) {
			return dp[x][y][con][max + 1] = 1;
		} else {
			return dp[x][y][con][max + 1] = 0;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 2; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx <= n && yy <= m) {
			if (max < maze[x][y]) {
				ans = (ans + dfs(xx, yy, con + 1, maze[x][y])) % mod;	
			}
			ans = (ans + dfs(xx, yy, con, max)) % mod;
		}
	}
	return dp[x][y][con][max + 1] = ans % mod;	
}
void solve()
{
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &maze[i][j]);
		}
	}
	dfs(1, 1, 0, -1);
	cout << dp[1][1][0][0] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

