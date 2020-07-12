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

struct node
{
    double x, y, z;
}amap[maxn];


int temp = 0, n;
double m, G[maxn][maxn];
double d[maxn];
int pre[maxn];
bool vis[maxn];

void Dijkstra(int s)
{

    fill(d, d + maxn, INF);
    d[0] = 0;
    for (int i = 0; i < n + 2; i++)
    {

        int u, MIN = INF;
        for (int j = 0; j < n + 2; j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
//        if (u == -1)
//            return;
        vis[u] = true;
        for (int v = 0; v < n + 2; v++)
        {
            if (d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
                pre[v] = u;

            }
        }

    }
}
void pr(int pos)
{
    if (pos == 0)return;
    pr(pre[pos]);
    if (pos!=n + 1)cout << pos << ' ';
}
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d%lf", &n, &m);
    scanf("%lf%lf%lf%lf%lf%lf", &amap[0].x, &amap[0].y, &amap[0].z, &amap[n + 1].x, &amap[n + 1].y, &amap[n + 1].z);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf%lf", &amap[i].x, &amap[i].y, &amap[i].z);
    for (int i = 0 ; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (i != j)
            {
                G[i][j] = sqrt((amap[i].x - amap[j].x) * (amap[i].x - amap[j].x) + (amap[i].y - amap[j].y) * (amap[i].y - amap[j].y) + (amap[i].z - amap[j].z) * (amap[i].z - amap[j].z));
                if (G[i][j] > m)
                    G[i][j] = INF;
//                cout << G[i][j] << endl;
            }

        }
    }
    Dijkstra(0);
        for (int i = 0; i < n; i++)
    {
        cout << d[i] <<endl;
    }
    if (d[n + 1] == INF)
        cout << -1 << endl;
    else
    {
        printf("%.3lf\n",d[n+1]);
        cout << "Start ";
        pr(n + 1);
        cout << "End" << endl;
    }
    return 0;
}

