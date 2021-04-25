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
int t, n, ans = INF, tmp;
char C[1005][1005];
bool M[1005][1005], vis[1005][1005];
int dir[5][2] = {0, 0, 1, 0, -1, 0, 0, -1, 0, 1};
bool check() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			if (!M[i][j]) return 0;
	return 1;
}
void turn(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= n) {
			M[xx][yy] = !M[xx][yy];
		}
	}
}
void dfs(int x, int y, int con) {
	if (check()) {
		ans = min(con, ans);
		return;
	}
	if (con > 6) return;
//	cout << x << ' ' << y << endl;
//	debug(con);
	tmp = max(tmp, con);
	for (int i = 1; i < 5; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5 && vis[xx][yy] == 0) {
			vis[xx][yy] = 1;
			dfs(xx, yy, con);
			vis[xx][yy] = 0;
			turn(xx, yy);
			vis[xx][yy] = 1;
			dfs(xx, yy, con + 1);
			vis[xx][yy] = 0;
			turn(xx, yy);
		}
	}

}

void solve()
{
	cin >> t;
	while (t--) {
		ans = INF;
		for (int i = 1; i <= 5; i++) {
			cin >> C[i] + 1;
		}
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				if (C[i][j] == '0') M[i][j] = 0;
				else M[i][j] = 1;
			}
		}
		vis[1][1] = 1;
		dfs(1, 1, 0);
		debug(1);
		turn(1, 1);
		
		dfs(1, 1, 1);
		turn(1, 1);
		vis[1][1] = 0;
		cout << ans << endl;
		debug(tmp);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

