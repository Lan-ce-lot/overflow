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
const int maxn = 100005;

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
};
node a[maxn];

int t, n;
double dis[1005][1005];

void floyd()
{
    for (int k = 1; k <= t; k++)
        for (int i = 1; i <= t; i++)
            for (int j = 1; j <= t; j++)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
}


void solve()
{
    int q = 1;
    while (cin >> t)
    {
        if (t == 0)
            return ;
        memset(dis, 0, sizeof(dis));
        for (int i = 1; i <= t; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        for (int i = 1; i <= t; i++)
        {
            for (int j = i + 1; j <= t; j++)
            {
                dis[i][j] = dis[j][i] = sqrt(double(a[i].x - a[j].x) * (a[i].x - a[j].x) + double(a[i].y - a[j].y) * (a[i].y - a[j].y));
//                debug(dis[i][j]);
            }
        }
        floyd();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",q++,dis[1][2]);
    }
}



int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

