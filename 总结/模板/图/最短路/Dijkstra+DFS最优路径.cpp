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

int n, m, st, ed, G[maxn][maxn], cost[maxn][maxn];
int d[maxn], c[maxn], pre[maxn];
bool vis[maxn];

void Dijkstra(int s)
{

    fill(d, d + maxn, INF);
    fill(c, c + maxn, INF);
    for (int i = 0; i < n; i++)
    {
        pre[i] = i;
    }
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if(vis[j] == false && d[j] < MIN)
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
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
                else if (d[u] + G[u][v] == d[v])
                {
                    if (c[u] + cost[u][v] < c[v])
                    {
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int v)
{
    if (v == st)
    {
        printf("%d ", v);
        return ;
    }
    DFS(pre[v]);
    printf("%d ", v);
}


int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    int v, u;
    fill(G[0], G[0] + maxn * maxn, INF);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d%d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", d[ed], c[ed]);
    return 0;
}

