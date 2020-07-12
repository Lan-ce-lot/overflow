/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 kruskal算法，最短的边加并查集
 稀疏图推荐用kruskal
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


int p[30];
struct node
{
    int u, v, w;
};

node maze[maxn];
int ans = 0;
bool cmp(node a, node b)
{
    return a.w < b.w;
}

void init()
{
    for (int i = 0; i < 100; i++)
        p[i] = i;
}

int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y, int i)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        ans += maze[i].w;
        p[x] = y;
    }
}

int t1, n;

void solve()
{
    while (cin >> t1)
    {
        init();
        if (t1 == 0)
            return;
        int k = 0;
        for (int i = 0; i < t1 - 1; i++)
        {
            char str1;
            int m;
            cin >> str1 >> m;

            for (int j = 0; j < m; j++, k++)
            {
                char str2;
                int t;
                cin >> str2 >> t;
                maze[k].u = (str1 - 'A');
                maze[k].v = (str2 - 'A');
                maze[k].w = t;
            }

        }

        sort(maze, maze + k, cmp);
        ans = 0;
        for (int i = 0; i < k; i++)
        {
            Union(maze[i].u, maze[i].v, i);
        }
        cout << ans << endl;
    }
}
int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

