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
int t, n, m, maze[1004][1005], ans = 0;
bool vis[1005][1005];
struct node
{
    int x, y, step;
};

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

bool test(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && !maze[x][y];
}

void bfs(int x, int y, int step)
{
    queue<node> Q;
    Q.push({x, y, step});
    vis[x][y] = 1;
    while (!Q.empty())
    {
        node top = Q.front();
        if (top.x == n - 1 && top.y == m - 1)
        {
            cout << top.step << endl;
            return ;
        }
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (test(top.x + dir[i][0], top.y + dir[i][1]))
            {
                Q.push({top.x + dir[i][0], top.y + dir[i][1], top.step + 1});
                vis[top.x + dir[i][0]][top.y + dir[i][1]] = 1;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = read();
        }
    }
    bfs(0, 0, 0);

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

