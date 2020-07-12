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
const int maxn = 500005;

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
int parent[maxn * 3];//x 是本身， x + n是猎物，x + 2 * n为天敌

void init()
{
    for (int i = 0; i <= 3 * n; i++)
        parent[i] = i;
}

int Find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}

void solve()
{
    cin >> n >> t;
    int z, x, y;
    int ans = 0;
    init();
    while (t--)
    {
        z = read();
        x = read();
        y = read();
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (z == 1)
        {
            if (Find(x + 2 * n) == Find(y) || Find(x + n) == Find(y))
            {
                ans++;
                continue;
            }
            else
            {
                Union(x, y);
                Union(x + n, y + n);
                Union(x + 2 * n, y + 2 * n);
            }
        }
        else if (z == 2)
        {
            if (Find(x) == Find(y) || Find(x) == Find(y + n))
            {
                ans++;
                continue;
            }
            else
            {
                Union(x, y + 2 * n);
                Union(x + n, y);
                Union(x + 2 * n, y + n);
            }
        }
    }
    cout << ans << endl;
}


int main()
{
    solve();
    return 0;
}

