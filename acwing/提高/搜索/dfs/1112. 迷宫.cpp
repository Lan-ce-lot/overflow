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
int st_x, st_y, en_x, en_y;
char maze[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool vis[1005][1005];
bool dfs(int x, int y) {
    if (!(maze[x][y] == '.' && vis[x][y] == 0 && x >=0 && y >= 0 && x < n && y < n)) return 0;
    if (x == en_x && y == en_y) return 1;

    for (int i = 0; i < 4; i++) {
        vis[x][y] = 1;
        if (dfs(x + dir[i][0], y + dir[i][1])) return 1;
    }
    return 0;
}


void solve()
{
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof vis);
        cin >> n;
        for (int i = 0; i < n; i++ ) {
            cin >> maze[i];
        }
        cin >> st_x >> st_y >> en_x >> en_y;


//        dfs(st_x, st_y);
        puts(dfs(st_x, st_y)? "YES":"NO");
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

