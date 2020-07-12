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
#include <vector>
#include <cstdio>
#include <sstream>
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
const int maxn = 1000005;

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

struct node
{
    double x, y;
};

node a[maxn];
int t, n;
bool vis[maxn];
double maze[1000][1000];
double d[maxn];
double dis(node a, node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void bell()
{
    fill(d, d + maxn, INF);
    memset(vis, 0, sizeof(vis));
    d[1] = 0;
    for (int i = 1; i <= n - 1; i++)
        for (int u = 1; u <= n; u++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!vis[j])
                {
                    d[j] = min(d[j], max(d[u], maze[u][j]));
                }
            }
        }
}

void solve()
{
    int icase = 0;
    while (cin >> n)
    {
        double minn = 10000000;
        if (!n)
            return;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &a[i].x, &a[i].y);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                maze[i][j] = maze[j][i] = dis(a[i], a[j]);
                minn = min(minn, maze[i][j]);
            }
        }
        bell();
        if(icase)
            printf("\n");
        printf("Scenario #%d\nFrog Distance = %.3f\n",++icase,d[2]);

    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

