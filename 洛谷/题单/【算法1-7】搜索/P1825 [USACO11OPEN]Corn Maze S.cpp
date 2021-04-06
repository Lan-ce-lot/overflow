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
int t, n, m, cnt;
char M[1005][1005];
bool vis[1005][1005];
struct node {
	int x, y, st;
}S, E;
struct zy {
	char c;
	int x, y;
}Z[27][2];
int len[27];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}, ff[27];
int bfs() {
	queue<node> Q;
	Q.push(S);
	vis[S.x][S.y] = 1;
	while (Q.size()) {
		node top = Q.front();
		Q.pop();
		if (top.x == E.x && top.y == E.y)
			return top.st;
		if (M[top.x][top.y] >= 'A' && M[top.x][top.y] <= 'Z') {
			char C = M[top.x][top.y];
			int f = 0;
			if (len[C - 'A'] == 2) {
				if (Z[C - 'A'][0].x == top.x && Z[C - 'A'][0].y == top.y) f = 1;	
				else f = 0;
				int xx = Z[C - 'A'][f].x, yy = Z[C - 'A'][f].y;
				top = {xx, yy, top.st};
			} 
		}
		for (int i = 0; i < 4; i++) {
			int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
			if (M[xx][yy] != '#' && !vis[xx][yy]) {
				Q.push({xx, yy, top.st + 1});
				vis[xx][yy] = 1;
			}
		}
	}
	return -1;
}

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> M[i] + 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (M[i][j] == '@') S = {i, j, 0};
			if (M[i][j] == '=') E = {i, j, 0};
			if (M[i][j] >= 'A' && M[i][j] <= 'Z') 
				Z[M[i][j] - 'A'][len[M[i][j] - 'A']++] = {M[i][j], i, j};
		}
	}
	cout << bfs() << endl;
}
int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
