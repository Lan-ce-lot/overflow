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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

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

ll t, n, m, k;
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%lld", &t);
    while (t--)
    {
        ll ans = 0;//这里竟然因为数据类型int和%lld卡了一下。。
        scanf("%lld%lld%lld",&n, &m, &k);
        int temp = n - k + 1;
        int max_1 = (m + 1) / (n - k + 1) + ((m + 1) % (n - k + 1) == 0 ? 0 : 1);
        ans = m + 1 +(k - 1) * max_1;
        printf("%lld\n", ans);
    }

    return 0;
}
