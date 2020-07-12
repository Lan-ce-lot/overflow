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
const int maxn = 10000005;

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
int a[maxn];

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int flag1 = 0;
        int flag2 = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = read();
            sum += a[i];
            if (a[i] & 1)
            {
                flag1 = 1;
            }
            else
            {
                flag2 = 1;
            }


        }
        if (flag1 && flag2)
        {
            puts("YES");continue;
        }

        if (sum&1)
        {
            puts("YES");continue;
        }
        puts("NO");
    }
}

int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

