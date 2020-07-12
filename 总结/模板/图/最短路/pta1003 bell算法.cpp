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

struct node
{
    int v, dis;
    node(int _v, int _dis) : v(_v), dis(_dis) {}
};

vector<node> Adj[maxn];
int n, m, st, ed, weight[maxn], u, v, wt;
int d[maxn], w[maxn], num[maxn];
set<int> pre[maxn];

void Bellman(int s)
{
    fill(d, d + maxn, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int j = 0; j < Adj[u].size(); j++)
            {
                int v = Adj[u][j].v;
                int dis = Adj[u][j].dis;
                if (d[u] + dis < d[v])
                {
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pre[v].clear();
                    pre[v].insert(u);
                }
                else if (d[u] + dis == d[v])
                {
                    if (w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                    pre[v].insert(u);
                    num[v] = 0;
                    set<int>::iterator it;
                    for (it = pre[v].begin(); it != pre[v].end(); it++)
                    {
                        num[v] += num[*it];
                    }
                }
            }
        }
    }

//    for (int u = 0; u < n; u++)
//    {
//        for (int j = 0; j < Adj[u].size(); j++)
//        {
//            int v = Adj[u][j].v;
//            int dis = Adj[u][j].dis;
//            if (d[u] + dis < d[v])
//            {
//                return false;
//            }
//        }
//    }
//    return true;
}

int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d%d%d%d", &n, &m, &st, &ed);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &wt);
        Adj[u].push_back(node(v, wt));
        Adj[v].push_back(node(u, wt));
    }
    Bellman(st);
    printf("%d %d\n", num[ed], w[ed]);
    return 0;
}

