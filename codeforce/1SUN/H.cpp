/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int t, n, m, count1 = 0;
int dir[8][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};
bool test(int x, int y)
{
    return maze[x][y] == '.' || vis[x][y] || x < 0 || x >= n || y < 0 || y >= m ;
}

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

bool dfs(int x, int y)
{
    if (test(x, y))
        return true;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dir[i][0], y + dir[i][1]);
    }

}



int main()
{
//    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!test(i, j))
            {
                count1 ++;
                dfs(i, j);
            }
    cout << count1 << endl;
    return 0;
}

