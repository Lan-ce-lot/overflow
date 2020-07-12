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
bool vis[10][10];
int dir[8][2] = {1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2};
struct Node{
    int x, y, step;

};

bool test(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8 && !vis[x][y]);
}
int ans = 0;
int bfs(int x, int y, int to_x, int to_y) {
    queue<Node> Q;
    Q.push({x, y, 0});
    vis[x][y] = 1;
    while (!Q.empty()) {
        Node top = Q.front();
        Q.pop();
        if (top.x == to_x&& top.y == to_y) {
            return top.step;
        }
        vis[top.x][top.y] = 1;
        for (int i = 0; i < 8; i++) {
            int xx = top.x + dir[i][0];
            int yy = top.y + dir[i][1];
            if (test(xx, yy)) {
                vis[top.x][top.y] = 1;
                Q.push({xx, yy, top.step + 1});
            }
        }
    }
    return -1;
}


void solve()
{
    char s1[10], s2[10];
    while (scanf("%s%s",s1,s2)==2) {
        int x_from = s1[0] - 'a' + 1;
        int y_from = s1[1] - '0';
        int x_to = s2[0] - 'a' + 1;
        int y_to = s2[1] - '0';
        memset(vis, 0, sizeof vis);
        ans = bfs(x_from, y_from, x_to, y_to);

        cout << "To get from " << s1 <<" to " << s2 << " takes " << ans << " knight moves." << endl;
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

