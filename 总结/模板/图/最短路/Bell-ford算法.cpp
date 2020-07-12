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
};
vector<node> Adj[maxn];
int n;
int d[maxn];

bool Bellman(int s)//判断负环
{
    fill(d, d + maxn, INF);
    d[s] = 0;
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
                }
            }
        }
    }

    for (int u = 0; u < n; u++)//判断负环
    {
        for (int j = 0; j < Adj[u].size(); j++)
        {
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if (d[u] + dis < d[v])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

//    ios::sync_with_stdio(false);

    return 0;
}

