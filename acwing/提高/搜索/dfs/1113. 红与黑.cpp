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
int t, n, m, st_x, st_y;
char maze[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool vis[1005][1005];

bool test(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && maze[x][y] == '.';
}

int dfs(int x, int y) {
    int cnt = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (!test(xx, yy)) continue;

        cnt += dfs(xx, yy);
    }
    return cnt;
}

void solve()
{
    while (cin >> m >> n, m || n) {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == '@') st_x = i, st_y = j;
            }
        }
        cout << dfs(st_x, st_y) << endl;

//        for (int i = 0; i < n; i++)
//            cout << maze[i];
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

