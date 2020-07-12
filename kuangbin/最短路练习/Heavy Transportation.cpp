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
const int maxn = 10005;

struct node
{
    int to;
    int s;
    node(int tt, int ss):to(tt), s(ss){}
};

vector<node> aa[maxn];
int d[maxn];
int vis[maxn];

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
int t, n, m;
int G[1005][1005];

void dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        d[i] = G[1][i];
    }
    vis[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int u = -1, MIN = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && d[j] > MIN)
            {
                u = j;
                MIN = d[u];
            }
        }
        if (u == -1)
            return ;
        vis[u] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                    d[j] = max(d[j], min(G[u][j], d[u]));
            }
        }

    }
}


void solve()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        memset(G, 0, sizeof(G));
        n = read();
        m = read();
        for (int j = 1; j <= m; j++)
        {
            int a, b, c;
            a = read();
            b = read();
            G[a][b] = G[b][a] = read();
        }
        dijkstra();
        cout << "Scenario #" << i << ":" << endl;
        cout << d[n] << endl << endl;
    }
}

int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

