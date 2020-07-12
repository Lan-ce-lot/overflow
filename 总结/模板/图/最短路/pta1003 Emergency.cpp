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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

int n, m, st, ed, G[maxn][maxn], weight[maxn];
int d[maxn], w[maxn], num[maxn];
bool vis[maxn] = {false};


void Dijkstra(int s)
{

    fill(d, d + maxn, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && G[u][v] != INF)
            {
                if (d[u] + G[u][v] < d[v])
                {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }
                else if (d[u] + G[u][v] == d[v])
                {
                    if (w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] +=num[u];
                }
            }
        }
    }
}

int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}
