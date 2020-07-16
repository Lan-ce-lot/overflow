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
int t, n, m, x, y;

int dir[8][2] = {2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1};
bool vis[15][15];
int ans = 0;

bool test(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m && (!vis[x][y]);
}

void dfs(int x, int y, int st) {
	if (st == n * m) {
		ans++;
		return ;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0) {
//		if (test(xx, yy)) {
			vis[xx][yy] = 1;
			dfs(xx, yy, st + 1);
			vis[xx][yy] = 0;
		}
	}
}

void solve()
{
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(vis, 0, sizeof vis);
		scanf("%d%d%d%d", &n, &m, &x, &y);
//		n = read(), m = read(), x = read(), y = read();
		vis[x][y] = 1;
		dfs(x, y, 1);
		printf("%d\n", ans);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

