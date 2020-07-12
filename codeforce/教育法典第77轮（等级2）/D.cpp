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
const int maxn = 1e6 + 5;

struct node
{
    int l, r, d;
} tra[maxn];


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
int m, n, k, t;
int a[maxn];

bool check(int n)
{
    int pre = 0, cur = 0;
    for (int i = 1, prei = 0; i <= n + 1; i++)
    {
        int maxR = -1;
        for (int j = 1; j <= k; j++)
        {
            if (tra[i].d <= a[n])
            {
                continue;
            }
            maxR = max(maxR, tra[i].r);
        }
        while (i < maxR)
        {
            ++i;
            for (int j = 1; j <= k; j++)
            {
                if (tra[j].d <= a[n])
                    continue;
                maxR = max(maxR, tra[j].r);
            }
        }
        if (maxR != -1)
            cur = pre + 3 * (i - prei);
        else
            cur = pre + 1;
        prei = i;
        pre = cur;
    }
    return cur <= t;
}


void solve()
{
    m = read();//
    n = read();//¾àÀë
    k = read();//ÏÝÚå
    t = read();//Ê±¼ä
    for (int i = 1; i <= m; i++)
    {
        a[i] = read();
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= k; i++)
    {
        tra[i].l = read();
        tra[i].r = read();
        tra[i].d = read();
    }
    //binary
    int L = 0, R = m;

    while (1)
    {
        int mid = (L + R) >> 1;
        if (L == mid)
        {
            if (check(mid))
            {
                cout << m - L << endl;
                return ;
            }
            else
            {
                cout << m - R << endl;
                return ;
            }
        }

        if (check(mid))
        {
            R = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
}

int t1;
int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

