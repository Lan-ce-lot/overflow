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
const int maxn = 1005;
int height[maxn];
int parent[maxn];
void init()
{
    for (int i = 0; i < maxn; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }

}
int Find(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}
/*
2
5 4
1 2
2 3
4 5
3 4
*/
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
            height[x]++;
    }
//    parent[y]=x;//若根不同，y并入x，则y的根为x，同理x也能并入y  这里随意
}

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

int t, n, tt;

void solve()
{
    cin >> t;
    while (t--)
    {
        init();
        set<int> tem;
        cin >> n >> tt;
        for (int i = 0; i < tt; i++)
        {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        for (int i = 1; i <= n; i++)
        {
            tem.insert(Find(i));
//            debug(height[i]);
        }cout << tem.size() << endl;
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

