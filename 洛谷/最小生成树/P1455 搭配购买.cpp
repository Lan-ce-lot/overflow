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
int G[105][105];
int dis[maxn];
int vis[maxn];

void prim()
{
    for (int i = 0; i < t; i++)
    {
        vis[i] = 0;
        dis[i] = G[0][i];
    }

    for (int i = 0; i < t; i++)
    {
        int u = -1, MIN = INF;

        for (int j = 0; j < t; j++)
        {
            if (!vis[j] && dis[j] < MIN)
            {
                u = j;
                MIN = dis[j];
            }
        }
        vis[u] = 1;
        for (int j = 0; j < t; j++)
        {
            if (!vis[j] && dis[j] > G[u][j])
            {
                dis[j] = G[u][j];
            }
        }

    }
    for (int i = 1; i < t; i++)
    {
        dis[0] += dis[i];
    }
    cout << dis[0] << endl;
}





void solve()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            G[i][j] = G[j][i] = read();
        }
    }
    prim();
}



int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

