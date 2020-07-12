/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: 注意有向图和无向图，
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const ll INF = 2147483647;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;
int a[maxn];

struct node
{
    int v, dis;
    node(int _v = 0, int _dis = 0) : v(_v), dis(_dis) {}
};

vector<node> Adj[maxn];
int n, m, st, ed, weight[maxn];//n点，m边
int d[maxn], num[maxn];//d存的是起点到各点的最短路
bool inq[maxn];

bool SPFA(int s)//s为起点
{
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d + maxn, INF);
    queue<int> Q;
    Q.push(s);
    inq[s] = true;
    num[s]++;
    d[s] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        inq[u] = false;
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if (d[u] + dis < d[v])
            {
                d[v] = d[u] + dis;
                if (!inq[v])
                {
                    Q.push(v);
                    inq[v] =true;
                    num[v]++;
                    if (num[v] >= n)
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Adj[a].push_back(node(b, c));
            Adj[b].push_back(node(a, c));
        }
        SPFA(1);
        printf("%d\n", d[n]);
        for (int i = 0; i <= n; i++)
        {
            Adj[i].clear();
        }
    }

    return 0;
}
//46MS	4728K
