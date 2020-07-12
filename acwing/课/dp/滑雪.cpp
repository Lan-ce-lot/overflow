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
int t, n, m, maze[1005][1005];
int dp[1005][1005];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int dfs(int x, int y)
{
//    if (x <= 0 || x > n || y <= 0 || y > m)
//    {
//        return 0;
//    }
    int &v = dp[x][y];
    if (v != -1)
        return dp[x][y];
    v = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dir[i][0], b = y + dir[i][1];
        if (a >= 1 && a <= n && b >= 1 && b <= m && maze[a][b] < maze[x][y])
        {
            v = max(dfs(a, b) + 1, v);
        }
    }
    return v;
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> maze[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res = max(res, dfs(i, j));
        }
    }
    cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

