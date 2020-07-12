/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
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
    node(int _v, int _dis) : v(_v), dis(_dis) {}
};

vector<node> Adj[maxn];
int n, m, st, ed, weight[maxn];
int d[maxn], num[maxn];
bool inq[maxn];

bool SPFA(int s)
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

    scanf("%d%d%d", &n, &m, &st);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        Adj[u - 1].push_back(node(v - 1, w));
    }
    SPFA(st - 1);
    for (int i = 0; i < n; i++)
    {
         printf(i == n -1 ?"%d\n" : "%d ", d[i]);
    }
    return 0;
}

