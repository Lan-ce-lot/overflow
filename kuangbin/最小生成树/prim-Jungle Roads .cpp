/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 prim 算法，类似迪杰斯特拉算法的思想
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
int t, n;
int G[1005][1005];
int dis[maxn];
int vis[maxn];

void prim()
{
    int mi, v;
    for (int i = 0; i < n; i++)
    {
        dis[i] = G[0][i];
        vis[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        mi = INF;
        for (int j = 0; j < n; j++)//找最短边
        {
            if (!vis[j] && mi > dis[j])
            {
                v = j;
                mi = dis[j];
            }
        }
        vis[v] = 1;
        for (int j = 0; j < n; j++)//更新
        {
            if (!vis[j] && dis[j] > G[v][j])
                dis[j] = G[v][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        dis[0] += dis[i];
    }
    cout << dis[0] << endl;
}





void solve()
{
    int m, w;
    char s[5], en[5];
    while ((cin >> n) && n)
    {
        memset(G, 63, sizeof(G));//发现的骚操作
        for (int i = 0; i < n; i++)
        {
            G[i][i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            scanf("%s%d", s, &m);
            for (int j = 0; j < m; j++)
            {
                scanf("%s%d", en, &w);
                G[s[0] - 'A'][en[0] - 'A'] = G[en[0] - 'A'][s[0] - 'A'] = w;
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

