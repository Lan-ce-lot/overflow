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
const int maxn = 3005;

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

int G[55][55];
int t, n, m ,ans;
int vis[55];
int dis[55];
void prim()
{

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        dis[i] = G[1][i];
    }
    for (int i = 1; i <= n; i++)
    {
        int u, MIN = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && MIN > dis[j])
                u = j, MIN = dis[j];
        }
        vis[u] = 1;



        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] > G[j][u])
            {
                dis[j] = G[j][u];
            }
        }
    }
    for (int i = 2; i <= n; i++)
        dis[1] += dis[i];
    cout << dis[1] << endl;
}


void solve()
{
    while (cin >> n, n)
    {
        cin >> m;
        ans = 0;
        memset(G, 63, sizeof(G));
        for (int i = 0; i < 55; i++)
            G[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            a = read();
            b = read();
            G[a][b] = G[b][a] = min(int(read()), G[a][b]);
        }
        prim();
    }
}



int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

