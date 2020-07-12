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
int t, n;
ll a[maxn], p[maxn];
void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int con = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[0] != -1 && a[1] == -1)
        {
            p[con++] = a[0];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] != -1)
            {
                if (a[i - 1] == -1 || a[i + 1] == -1)
                {
                    p[con++] = a[i];
                }
            }
        }
        if (a[n - 1] != -1 && a[n - 2] == -1)
        {
            p[con++] = a[n - 1];
        }
        ll step = *max_element(p, p + con) + *min_element(p, p + con);
        ll bb = *max_element(p, p + con) - *min_element(p, p + con);
        if (bb & 1)
        {
            bb = bb / 2 + 1;
        }
        else
        {
            bb = bb / 2;
        }
//        debug(step);
        step = step / 2;
        ll temp = 0, ans1 = 0, k;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] != -1 && a[i + 1] != -1)
            {
                temp = max(temp, abs(a[i] - a[i + 1]));
            }
        }
        ans1 = max(bb, temp);

        cout << ans1 << ' ' << step << endl;
    }
}
/*
100
5
-1 -1 -1 -1 5
5
5 -1 -1 -1 0
6
100 90 -1 -1 0 10
*/
int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

