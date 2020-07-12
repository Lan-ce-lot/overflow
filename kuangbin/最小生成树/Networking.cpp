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
const int maxn = 3005;

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

int p[55];
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

int t, n, m;

void solve()
{
    while (cin >> n, n)
    {
        cin >> m;
        init();
        ans = 0;
        for (int i = 0; i < m; i++)
        {
            maze[i].u = read();
            maze[i].v = read();
            maze[i].w = read();
        }

        sort(maze, maze + m, cmp);
        for (int i = 0; i < m; i++)
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

