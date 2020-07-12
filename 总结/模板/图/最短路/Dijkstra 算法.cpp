/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: 迪杰斯特拉，无负权值，pre[]保存上一结点，DFS递归打印路径
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

int n, G[maxn][maxn];
int d[maxn];
int pre[maxn];
bool vis[maxn];

void Dijkstra(int s)//s起点
{

    fill(d, d + maxn, INF);
    d[0] = 0;
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
            if (vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
                pre[v] = u;

            }
        }
//        for (int v = 0; v < n; v++)//×î¶ÌÂ·¾¶ÌõÊý
//        {
//            if (vis[v] == false &&G[u][v] != INF)
//            {
//                if (d[u] + G[u][v] < d[v])
//                {
//                    d[v] = d[u] + G[u][v];
//                    num[v] = num[u];
//                }
//                else if (d[u] + G[u][v] == d[v])
//                {
//                    num[v] += num[u];
//                }
//            }
//
//        }

    }
}


void DFS(int s, int v)//s起点
{

    if (v == s)
    {

        printf("%d\n", s);
        return ;
    }
    DFS(s, pre[v]);
    printf("%d\n", v);
}
int main()
{
//    ios::sync_with_stdio(false);
    return 0;
}

