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
const double INF = 10000000;//int2147483647//ll9e18//unsigned ll 1e19
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
    double x, y, z, r;
}a[maxn];



int t, n, m;
int vis[maxn];
double dis[maxn];
double G[maxn][maxn];

double getlen(node a, node b)
{
    double tem = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    if (tem > a.r + b.r)
        return tem - a.r - b.r;
    return 0;
}


void prim()
{
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        dis[i] = G[0][i];
    }
    for (int i = 0; i < n; i++)
    {
        int u;
        double MIN = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && MIN > dis[j])
            {
                u = j;
                MIN = dis[j];

            }
        }
        vis[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && dis[j] > G[u][j])
            {
                dis[j] = G[u][j];
            }

        }
    }
    for (int i = 1; i < n; i++)
        dis[0] += dis[i];
    printf("%.3lf\n", dis[0]);
}

void solve()
{
    while (cin >> n, n)
    {
        m = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j] = INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z, &a[i].r);
        }
        for (int i = 0; i < n; i++)
        {
            G[i][i] = 0;
            for (int j = i + 1; j < n; j++)
            {
                G[i][j] = G[j][i] = getlen(a[i], a[j]);
            }
        }
        prim();
    }
}

int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

