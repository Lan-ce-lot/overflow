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
const int maxn = 1e3 + 5;

struct  node
{
	int v, dis;//目标顶点，边权
    bool operator < (const node &rhs) const
    {
        return dis > rhs.dis;//距离
    }
};
vector<node > Adj[maxn];
int n, m, s;
int d[maxn];
bool vis[maxn];

void Dijkstra(int s)
{
    priority_queue<node> que;

    memset(vis, 0, sizeof(vis));
    fill(d, d + maxn, INF);

    d[s] = 0;
    que.push((node){s, d[s]});
    while (!que.empty())
    {
        int now = que.top().v;
        node tp = que.top();
        que.pop();
        if (d[now] < tp.dis)//f=dis,s=v
            continue;
        for (int i = 0; i < Adj[now].size(); i++)
        {
            int v = Adj[now][i].v;
            if (d[v] > d[now] + Adj[now][i].dis)
            {
                d[v] = d[now] + Adj[now][i].dis;
                que.push((node){v, d[v]});
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Adj[a].push_back((node){b, c});
            Adj[b].push_back((node){a, c});
        }
        Dijkstra(1);
        printf("%d\n",d[n]);
        for (int i = 0; i <= n; i++)
            Adj[i].clear();
    }
    return 0;
}

