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

//struct  node
//{
//	int v, dis;//目标顶点，边权
//	node(int _v, int _dis) : v(_v), dis(_dis) {}
//};
vector<pair<int, int> > Adj[maxn];
typedef pair<int, int> p;
int n, m, s;
int d[maxn];
int pre[maxn];
bool vis[maxn];

void Dijkstra(int s)
{
    priority_queue<p, vector<p>, greater<p> > que;
    fill(d, d + maxn, INF);
    d[s] = 0;
    que.push(make_pair(d[s], s));
    while (!que.empty())
    {
        int now = que.top().second;
        p tp = que.top();
        que.pop(); 
        if (d[now] < tp.first)
            continue;
        for (int i = 0; i < Adj[now].size(); i++)
        {
            int v = Adj[now][i].second;
            if (d[v] > d[now] + Adj[now][i].first)
            {
                d[v] = d[now] + Adj[now][i].first;
                que.push(make_pair(d[v], v));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s;
    int v, u, w;
    for (int i = 0; i < m; i++)
    {
    	cin >> u >> v;
		cin >> w;
		Adj[u ].push_back(make_pair(w, v));
    }
    Dijkstra(s);
    for (int i = 1; i <= n; i++)
    {
        cout << d[i] ;
        i == n  ? cout << endl : cout << ' ';
    }
    return 0;
}
