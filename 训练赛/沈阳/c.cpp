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

struct node
{
	int x, y;
}a[maxn];

bool cmp(node a, node b)
{
    if (a.y * b.x != b.y * a.x)
        return a.y * b.x > b.y * a.x;
    return a.x < b.x;
}

int dp[maxn][maxn];

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
int t, n, m;
int main()
{
//    ios::sync_with_stdio(false);
	while(~scanf("%d%d", &n, &m))
	{
	    int ans = 0;
		for(int i = 0, j = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].x, &a[i].y);
		}

		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++)
            printf("%d %d\n", a[i].x, a[i].y);
		int temp_d = m / a[i].x;
		int temp_y = m % a[i].x;
		for (int i = 1; i < n; i++)
        {
            if ()
            {

            }
        }


		ans = max(a[i].x * m, a[i].x * m );
		if ()



		printf("%d\n", ans);
	}


    return 0;
}

