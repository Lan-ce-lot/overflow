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

int t, n, m;
char maze[100][100];
bool vis[105][105];
int s_x, s_y, e_x, e_y, sum_l;

bool test(int x, int y) {return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != 'X' && !vis[x][y];}

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

bool dfs(int x, int y, int nt) {
    if (nt > t) return 0;
    if (nt == t && x == e_x && y == e_y) return 1;
    int c = t - nt - abs(e_x - x) - abs(e_y - y);// 剪枝
    if (c < 0 || c & 1) return 0;

    for (int i = 0; i < n; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (test(xx, yy)) {
            vis[xx][yy] = 1;

            if (dfs(xx, yy, nt + 1))
                return 1;

            vis[xx][yy] = 0;
        }
    }
    return 0;
}

void solve()
{
    while (cin >> n >> m >> t, t && n && m) {
        memset(vis, 0, sizeof vis);

        for (int i = 0; i < n; i++) scanf("%s", maze[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] == 'S') s_x = i, s_y = j;
                else if (maze[i][j] == 'D') e_x = i, e_y = j;

        sum_l = abs(s_x - e_x) + abs(s_y - e_y);
        vis[s_x][s_y] = 1; // 开始标记!!!!!

        if (sum_l > t) puts("NO");
        else puts(dfs(s_x, s_y, 0) ? "YES" : "NO");
    }
}

int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

