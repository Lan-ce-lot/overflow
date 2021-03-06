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
int maze[1005][1005], sum = 0;
int ans = INF;
bool vis[1005][1005];
bool fal[1005][1005];
vector<PII> G;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void dfs(int tem, int step) {
	if (tem == sum / 2) {
		ans = min(ans, step);
		return ;
	}
	if (tem > sum / 2) {
		return;
	}
	if (step >= ans) {
		return;
	}
	for (int k = 0; k < G.size(); k++) {
		int x = G[k].first, y = G[k].second;
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0 && fal[xx][yy] == 0) {
				vis[xx][yy] = 1;
				G.push_back({xx, yy});
				dfs(tem + maze[xx][yy], step + 1);
				G.pop_back();
				vis[xx][yy] = 0;
				fal[xx][yy] = 1;
			}
		}
	}

}

void solve()
{
	n = read(), m = read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maze[i][j] = read();
			sum += maze[i][j];
		}
	}
	vis[0][0] = 1;
	G.push_back({0, 0});
	dfs(maze[0][0], 1);
	cout << ans << endl	;
}

int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

