/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: 注意是无向图还是有向图
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
const int maxn = 1e3 + 5;

struct node
{

    int v, dis;                 //v:to,dis:cost
    node(int _v = 0, int _dis = 0) : v(_v), dis(_dis){}
};

vector<node> Adj[maxn];//邻接表
int n, m;//n点，m路
int d[maxn];
bool vis[maxn];

void Dijkstra(int s)//s为起点
{
    fill(d, d + maxn, INF);
    memset(vis, false, sizeof(vis));
    d[s] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++)
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
            if (vis[v] == false && d[u] + Adj[u][j].dis < d[v])
            {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    while(~scanf("%d%d", &n, &m))
    {
    	
        if (n == 0 && m == 0)
            break;
        int a, b, c;
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Adj[a].push_back(node(b, c));

            Adj[b].push_back(node(a, c));//注意是无向图还是有向图
        }
        Dijkstra(1);
        printf("%d\n", d[n]);
        
		//记得清空，卡了半天，气死了         
        for (int i = 0; i <= n;i++)
    		Adj[i].clear(); 
    		
    }
    return 0;
}
//15MS	1508K
