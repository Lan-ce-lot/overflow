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
const int maxn = 250005;

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
int t, n, m, d, ans;

int parent[maxn];
int sum[maxn];
int Find(int x)
{
    if (x == parent[x])
        return x;
    int t = parent[x];
    parent[x] = Find(parent[x]);
    sum[x] += sum[t];
    return parent[x];
}

void Union(int x, int y)
{
    int a = Find(x);
    int b = Find(y);
    if (a == b)
    {
        if (sum[y] != sum[x] + d)
            ans ++;
        return;
    }
    if (a > b)
    {
        sum[a] = sum[y] - (sum[x] + d);
        parent[a] = b;

    }
    else
    {
        sum[b] = sum[x] + d - sum[y];
        parent[b] = a;
    }
    return;
}

void solve()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            sum[i] = 0;
        }
        int sa, en;
        ans = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> sa >> en >> d;
            Union(sa - 1, en);
        }
        cout << ans << endl;
    }
}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

