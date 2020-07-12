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
const int maxn = 1e5 + 5;
ll f[maxn];
void fb()
{
    for (int i = 1; i <= 1000; i++)
    {
        f[i] += f[i - 1] + i;
    }
}

struct node
{
    ll x, y;
} a[maxn];

bool cmp (node a, node b)
{
    if (a.x * b.y == b.x * a.y)
        return a.x < b.x;
    return a.x * b.y < b.x * a.y;
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


ll ans;
int t, n;
int main()
{
//    ios::sync_with_stdio(false);
    fb();
//    for (int i= 1; i < 100; i++)
//        cout << f[i] <<endl;
    t = read();
    for (int k = 1; k <= t ; k++)
    {
        ans = 0;
        n = read();
        for (int i = 0; i < n; i++)
        {
            a[i].x = read();
            a[i].y = read();
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < maxn; j++)
            {
//                if (a[i].x * 2 <= j * (j + 1))
                if (a[i].x <= f[j])
                {
                    a[i].x = j;
                    break;
                }
            }
        }
        sort(a, a + n, cmp);
//        for (int i =0; i < n; i++)
//        {
//            cout << a[i].x << a[i].y << endl;
//        }
        ll temp = 0;
        for (int i = 0; i < n; i++)
            temp += a[i].y;
        for (int i = 0; i < n; i++)
        {
            ans += a[i].x * temp;
            temp -= a[i].y;
        }
        printf("Case #%d: %lld\n", k, ans);
    }
    return 0;
}
