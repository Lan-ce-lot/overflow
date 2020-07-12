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
int t, n, m, time = 6;

bool vis[1004][1004];
int maze[1004][1004];
int ans = -1;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
struct node{
    int x, y;
    int step, no;
};

bool test(int x, int y, int t) { return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] && t < 6;}

bool bfs(int x, int y, int step, int time) {
    queue<node> Q;
    vis[x][y] = 1;
    Q.push({x, y, step, time});
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        if (maze[top.x][top.y] == 3) {ans = top.step;return 1;}
//cout << top.x << ' ' << top.y << endl << maze[top.x][top.y] <<endl << top.no;
//debug(top.step);
        for (int i = 0; i < 4; i++) {
            int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
            int tt = top.no + 1;
            if (test(xx, yy, tt)) {
                if (maze[xx][yy] == 4) {
                    Q.push({xx, yy, top.step + 1, 0});
                    maze[xx][yy] = 0;
                    vis[xx][yy] = 1;
                } else {
                    Q.push({xx, yy, top.step + 1, tt});
                    vis[xx][yy] = 1;
                }
            }
        }
    }
    return 0;
}

void solve()
{
    scanf("%d", &t);
    while (t--) {
        ans = -1;
        int st_x, st_y, end_x, end_y;
        memset(vis, 0, sizeof vis);
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &maze[i][j]);
                if (maze[i][j] == 2) st_x = i, st_y = j;
            }
        }
//        cout << st_x << ' ' <<st_y << endl;
        bfs(st_x, st_y, 0, 0);

        printf("%d\n", ans);
    }

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

