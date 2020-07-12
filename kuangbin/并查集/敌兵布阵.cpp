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
const int maxn = 10005;

struct node
{
    int x;
    int y;
    int num;
};

node aa[maxn];
int parent[maxn];
int height[maxn];
bool vis[maxn];

void init()
{
    for (int i = 1; i <= maxn ; i++)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

int Find(int x)//
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);//路径压缩
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
        //
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

bool same(int x, int y)
{
    return Find(x) == Find(y);
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
int t, n;
void dd()
{
    for (int i = 1; i <= t; i++)
        cout << parent[i] << ' ';
    puts("");
}
double getD(int u, int v)
{
    int x = aa[u].x - aa[v].x;
    int y = aa[u].y - aa[v].y;
    return sqrt(1.0 * x * x + 1.0 * y * y);
}


int fix[maxn], cnt = 0;
void solve()
{

    cin >> t >> n;
    for (int i = 1; i <= t; i++)
        parent[i] = i;
    for (int i = 1; i <= t; i++)
    {
        cin >> aa[i].x >> aa[i].y;
    }
    char str[2];
    while (~scanf("%s", str))
    {
        int q, p;
        if (str[0] == 'O')
        {
            cin >> p;
            if (vis[p])
                continue;
            vis[p] = 1;
            fix[++cnt] = p;
            for (int i = 1; i < cnt; i++)
            {
                int u = fix[i];
                double xxx = getD(u, p);
                if (xxx <= n)
                {
                    Union(u, p);

                }
            }
        }
        else
        {
            cin >> p >> q;
            int fu = Find(p);
            int fv = Find(q);

            puts(fu == fv ? "SUCCESS" : "FAIL");
        }
    }
}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*
4 1
0 1
0 2
0 3
0 4

O 1
O 2
O 4
S 1 4
O 3
S 1 4*/
