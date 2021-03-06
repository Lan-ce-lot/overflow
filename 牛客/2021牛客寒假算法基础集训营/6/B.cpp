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
int s_x, s_y, e_x, e_y;
bool vis[1005][1005];
char maze[1005][1005];
struct node {
	int x, y, step;
};
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool check(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && maze[x][y] != '#') {
		return 1;
	}
	return 0;
}
bool bfs() {
	queue<node> Q;
	Q.push({s_x, s_y, 0});
	vis[s_x][s_y] = 1;
	while (Q.size()) {
		node top = Q.front();
		Q.pop();
		if (top.x == e_x && top.y == e_y) {
			cout << top.step * 100 << endl;
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
			if (check(xx, yy)) {
				vis[xx][yy] = 1;
				Q.push({xx, yy, top.step + 1}); 
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
void solve()
{
	n = read(), m = read();
	s_x = read(), s_y = read(), e_x = read(), e_y = read();
	s_x--, s_y--, e_x--, e_y--;
	for (int i = 0; i < n; i++) {
		scanf("%s", maze[i]);
	}
	bfs();
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

