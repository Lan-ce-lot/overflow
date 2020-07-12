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

int t, n;
double ans;

struct node
{
    int x, y;
    double angel, r;
    node(int _x = 0, int _y = 0, double _angel = 0, double _r = 0) : x(_x), y(_y), r(_r), angel(_angel){};
} a[maxn];

node point;

double get_r(node a, node b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
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

int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d", &t);
    for (int k = 1; k <= t; k++)
    {
        ans = 0;
        n = read();
        for (int i = 0; i < n; i++)
        {
            a[i].x = read();
            a[i].y = read();
        }
        point.x = read();
        point.y = read();

        for (int i = 0; i < n; i++)
        {
            a[i].r = get_r(a[i], point);
            double d1 = get_r(a[i], a[(i + 1) % n]);
            double d2 = get_r(a[i], a[(i + n - 1) % n]);
            double d3 = get_r(a[(i + 1) % n], a[(i + n - 1) % n]);
            ans += sqrt(a[i].r) * (pi - acos((d1 + d2 - d3) / (2 * sqrt(d1) * sqrt(d2)))) ;
        }

        printf("Case #%d: %.3lf\n", k, ans);
    }
    return 0;
}

