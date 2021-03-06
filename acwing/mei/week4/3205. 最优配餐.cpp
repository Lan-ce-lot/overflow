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
int t, n, m, k, d;
int dis[1005][1005];
bool vis[1005][1005];
PII tar[1005 * 1005];
int sum[1005 * 1005];
queue<PII> Q;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
void bfs() {
	while (Q.size()) {
		PII top = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = top.first + dir[i][0], yy = top.second + dir[i][1]; 
			if (xx < 1 || xx > n || yy < 1 || yy > n || vis[xx][yy]) continue;
			if (dis[xx][yy] > dis[top.first][top.second] + 1) {
				dis[xx][yy] = dis[top.first][top.second] + 1;
				Q.push({xx, yy});
			}
		} 
	}
}
void solve()
{
	n = read(), m = read(), k = read(), d = read();
	memset(dis, 0x3f, sizeof dis);
	for (int i = 0; i < m; i++) {
		int x = read(), y = read();
		Q.push({x, y});
		dis[x][y] = 0;
	}
	
	for (int i = 0; i < k; i++) {
		tar[i].first = read(), tar[i].second = read(), sum[i] = read();
	}
	
	
	for (int i = 0; i < d; i++) {
		vis[read()][read()] = 1;
	}
	bfs();
	ll ans = 0;
	for (int i = 0; i < k; i++) {
		ans += dis[tar[i].first][tar[i].second] * sum[i];
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

