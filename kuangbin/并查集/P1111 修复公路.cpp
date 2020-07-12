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
const int maxn = 200000;

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
int t, n;//v way
int parent[maxn];
int height[maxn];

struct node
{
    int x, y, ss;
};
node a[maxn];
bool cmp(node a, node b)
{
    return a.ss < b.ss;
}

void init()
{
    for (int i = 1; i <= t; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

int Find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    if (height[x] < height[y])
        parent[x] = y;
    else
    {
        parent[y] = x;
        if (height[x] == height[y])
        {
            height[x] ++;
        }
    }
}

bool test()
{
    for (int i = 2; i <= t; i++)
    {
        if (parent[1] != parent[i])
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{

    cin >> t >> n;
    int con = t;
    for (int i = 0; i < n; i++)
    {
        a[i].x = read();
        a[i].y = read();
        a[i].ss = read();
    }
    int ans = 0;init();
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (Find(a[i].x) != Find(a[i].y))
        {
            ans = a[i].ss;
            con--;
            Union(a[i].x, a[i].y);
        }
        if (con == 1)
        {
            cout << ans << endl;
            return ;
        }
    }

    cout << -1 << endl;
}




int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

