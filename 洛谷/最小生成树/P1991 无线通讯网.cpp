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
const int maxn = 1000001;

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
    int x, y;
    double w;
}a[maxn];

bool cmp(node a, node b)
{
    return a.w < b.w;
}

int p[maxn];
double ans = 0;

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

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    p[y] = x;
}

int t, n, m, s, p1;


int xx[maxn], yy[maxn];

void solve()
{
    int k = 0;
    init();
    cin >> s >> p1;
    m = 0;
    for (int i = 0; i < p1; i++)
    {
        int x, y;
        scanf("%d%d", &xx[i], &yy[i]);
        for (int j = 0; j < i; j++)
        {
            a[m].x = i;
            a[m].y = j;
            a[m++].w = sqrt((xx[i] - xx[j]) * (xx[i] - xx[j]) + (yy[i] - yy[j]) * (yy[i] - yy[j]));
        }
    }

    sort(a, a + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (Find(a[i].y) != Find(a[i].x))
        {
            Union(a[i].y, a[i].x);

            ans = a[i].w;
            k++;
            if (k >= p1 - s)
            {
                printf("%.2lf\n", ans);
                return;
            }
        }
    }

}


int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

