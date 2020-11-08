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
int t, n, m;
int ma[1005][1005];
int dp[1005][1005];

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int dfs(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	
	int t = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && ma[xx][yy] > ma[x][y]) {
			t = max(t, dfs(xx, yy) + 1);
		}
	}
	dp[x][y] = t;
	return t;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ma[i][j] = read();
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int t = dfs(i, j);
			dp[i][j] = t;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

