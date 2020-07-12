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
    int v, dis;
};

vector<node> Adj[maxn];
int n, d[maxn], num[maxn];
bool inq[maxn];
bool SPFA(int s)
{
    memset(inq, false, sizeof(inq));
    memset(num, 0, sizeof(num));
    fill(d, d + maxn, INF);
    queue<int > Q;
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
                    inq[v] = true;
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
//    ios::sync_with_stdio(false);


    return 0;
}

