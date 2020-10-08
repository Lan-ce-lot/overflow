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
int G[6][6];

bool vis[6][6];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
struct node {
	int x, y;
	string st;
};


void bfs(int x, int y) {
	queue<node> Q;
	Q.push({x, y, "(0, 0)\n"});
//	cout << Q.front().st << endl;
	vis[x][y] = 1;
	while (!Q.empty()) {
		node top = Q.front();
		Q.pop();
		if (top.x == 4 && top.y == 4) {
			cout << top.st;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
			if (vis[xx][yy] == 0 && G[xx][yy] == 0 && xx <= 4 && xx >= 0 && yy <= 4 &&yy >= 0) {
				vis[xx][yy] = 1;
				Q.push({xx, yy, top.st + '(' + char(xx + '0') + ", " + char(yy + '0') + ")\n"});
			}
		} 
	}
	
}

void solve()
{
	n = 5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = read();
		}
	}
	bfs(0, 0);
	
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

