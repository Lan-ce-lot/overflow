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

ll LCM(ll a, ll b)
{
    return a * b / __gcd(a, b);
}
ll t, n, m, a[maxn], b[maxn];
int main()
{
//    ios::sync_with_stdio(false);
    while (~scanf("%lld%lld", &n, &m))
    {
        ll temp = 1;
        ll sum = 0, sum1 = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            temp = LCM(a[i], temp);
            sum1 += a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            b[i] = temp / a[i];
            sum += b[i];
        }
        if (!(m % sum))
        {
            printf("Yes\n");
            for (int i = 1; i <= n; i++)
            {
                printf(i == n ? "%lld\n" : "%lld ", b[i] * (m / sum));
            }
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

