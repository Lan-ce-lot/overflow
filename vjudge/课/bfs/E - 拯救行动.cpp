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
#include <stdlib.h>
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
int t, n, m, s_x, s_y, e_x, e_y, ans;
char maze[205][205];
bool vis[205][205];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
struct node{
    int x, y, step;
    bool operator < (const node &W)const{return step > W.step;}// 从小到大
};


bool test(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && maze[x][y] != '#';
}

bool bfs(int x, int y) {
    priority_queue<node> Q;// 迪杰斯特拉堆优化
    Q.push({x, y, 0});
    vis[x][y] = 1;
    while (!Q.empty()) {
        node top = Q.top();
//        cout << top.x << top.y << top.step << endl;
        Q.pop();
        if (top.x == e_x && top.y == e_y) {ans = top.step;return 1;};
        for (int i = 0; i < 4; i++) {
            int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
            if (test(xx, yy)) {
                vis[xx][yy] = 1;
                if (maze[xx][yy] == 'x')
                    Q.push({xx, yy, top.step + 2});
                else
                    Q.push({xx, yy, top.step + 1});
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 'r') {
                    s_x = i, s_y = j;
                }
                if (maze[i][j] == 'a') {
                    e_x = i, e_y = j;
                }
            }
        }
        char str[100];
        puts(bfs(s_x, s_y) ? sprintf(str, "%d", ans), str : "Impossible");
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
