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
const int maxn = 100005;

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
    int x, y, w;
}a[maxn];

bool cmp(node a, node b)
{
    return a.w < b.w;
}

int p[maxn], ans = 0;

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        p[i] = i;
    }
}

int Find(int x)
{
    return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int x, int y, int i)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    p[y] = x;
    ans = max(ans, a[i].w);
}

int t, n, m;

void k()
{
    for (int i = 0; i < m; i++)
    {
        Union(a[i].x, a[i].y, i);
    }
    cout << n - 1 << ' ' << ans << endl;
}






void solve()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        a[i].x = read();
        a[i].y = read();
        a[i].w = read();
    }
    sort(a, a + m, cmp);
    k();
}
int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

