/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description://迪杰斯特拉
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
const int maxn = 1000005;

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

struct node
{
    int to;
    int v;
    node(int tt = 0, int vv = 0) : to(tt), v(vv) {}
};
int t, n, m;
vector<node > Gap[maxn];
int d[maxn];
bool vis[maxn];

void Dijkstra(int s)
{
    fill(d, d + maxn, INF);
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++)//进集合
        {
            if (vis[j] == 0 && d[j] < MIN)//未经过且最近
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)//若无通路了，则退出
            return;
        vis[u] = 1;
        for (int j = 0; j < Gap[u].size(); j++)//u的邻结点
            if (vis[Gap[u][j].to] == 0)//未经过且可松弛更新
                d[Gap[u][j].to] = min(d[u] + Gap[u][j].v, d[Gap[u][j].to]);
    }
}

void solve()
{
    cin >> m >> n;
    while (m--)
    {
        int ta, tb, va;
        cin >> ta >> tb >> va;
        Gap[ta].push_back(node(tb, va));
        Gap[tb].push_back(node(ta, va));
    }
    Dijkstra(1);
    printf("%d\n", d[n]);

}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

