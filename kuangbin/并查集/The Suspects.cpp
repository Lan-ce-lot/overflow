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
const int maxn = 30005;

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
    for (int i = 0; i <= maxn ; i++)
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
//        //
//    if (height[x] < height[y])
//        parent[x] = y;
//    else
//    {
//        parent[y] = x;
//        if (height[x] == height[y])
//            height[x]++;
//    }
    parent[y]=x;//若根不同，y并入x，则y的根为x，同理x也能并入y  这里随意
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
    for (int i = 0; i < t; i++)
        cout << parent[i] << ' ';
    puts("");
}



int fix[maxn], cnt = 0;
int a1, b1;
int rec[maxn];
void solve()
{
    while (cin >> t >> n)
    {
        if (t == 0&& n == 0)
            return;
        init();
        int tt;

        for ( int i = 0; i < n; i++)
        {
            cin >> tt;
            bool flag = 0;
            for (int j = 0; j < tt; j++)
            {
                cin >> rec[j];
            }
            for (int j = 0; j < tt; j++)
            {
                if (rec[j] == 0 || Find(rec[j]) == 0)
                {

                    flag = 1;
                    break;
                }
            }
            for (int j = 0; j < tt; j++)
            {
                if (flag)
                {
                    Union(0, rec[j]);
                }
                else
                {
                    Union(rec[0], rec[j]);
                }
            }

        }

        int ans = 0;
        for (int i = 0; i < t; i++)
        {
            if (Find(i) == 0)
            {
                ans ++;
            }


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
