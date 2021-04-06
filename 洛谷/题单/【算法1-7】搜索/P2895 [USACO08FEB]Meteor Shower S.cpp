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
int t, n, dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool vis[1005][1005], z[1005][1005], s[1005][1005];

struct node {
	int x, y, t;
}N[maxn];

vector<node> a[1005];
bool check(int x, int y) {
	return x >= 0 && y >= 0 && vis[x][y] == 0 && z[x][y] == 0;
}

int bfs() {
	queue<node> Q;
	Q.push({0, 0, 0});
	vis[0][0] = 1;
	for (auto it : a[0])
		z[it.x][it.y] = 1;
	while (Q.size()) {
		node top = Q.front();
		Q.pop();
		if (!s[top.x][top.y]) {
//			debug(top.x);
//			debug(top.y);
			return top.t;
		}
		
		for (auto it : a[top.t + 1])
			z[it.x][it.y] = 1;
		for (int i = 0; i < 4; i++) {
			int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
			if (check(xx, yy)) {
				Q.push({xx, yy, top.t + 1});
				vis[xx][yy] = 1;
			}
		}
	}
	return -1;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
//		cin >> N[i].x >> N[i].y >> N[i].t, s[N[i].x][N[i].y] = 1, a[N[i].t].push_back(N[i]);
		N[i] = {read(), read(), read()};
		s[N[i].x][N[i].y] = 1, a[N[i].t].push_back(N[i]);
		for (int j = 0; j < 4; j++) {
			int xx = N[i].x + dir[j][0], yy = N[i].y + dir[j][1];
			if (xx >= 0 && xx <= 300 && yy >= 0 && yy <= 300)
				a[N[i].t].push_back({xx, yy, 0}), s[xx][yy] = 1;
		}
	}

	cout << bfs() << endl;
}

int main()
{

//    freopen("D:/work/C++/old/master/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

