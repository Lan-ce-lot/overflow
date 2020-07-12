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
const ll INF = 2147483647;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 + 5;

struct  node
{
	int v, dis;//目标顶点，边权 
	node(int _v, int _dis) : v(_v), dis(_dis) {}
};
vector<node> Adj[maxn];

int n, m, s;
int d[maxn];
int pre[maxn];
bool vis[maxn];

void Dijkstra(int s)
{

    fill(d, d + maxn, INF);
    for (int i = 0; i < n; i++)
    {
    	pre[i] = i;
	}
	d[s] = 0;
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
        for (int j = 0; j < Adj[u].size(); j++)
        {
        	int v = Adj[u][j].v;
            if (vis[v] == false &&  d[u] + Adj[u][j].dis < d[v])
            {
                d[v] = d[u] + Adj[u][j].dis;
                pre[v] = u;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    int v, u, w;
    for (int i = 0; i < m; i++)
    {
    	cin >> u >> v;
		cin >> w;
		Adj[u - 1].push_back(node(v - 1, w));
    }
    Dijkstra(s - 1);
    for (int i = 0; i < n; i++)
    {
        cout << d[i] ;
        i == n - 1 ? cout << endl : cout << ' ';
    }
    return 0;
}
