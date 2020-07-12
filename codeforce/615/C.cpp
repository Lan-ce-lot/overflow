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
int t, n, a, b ,c;

void solve()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
//for (int k = 0; k < 100; k++)
//{
//
//n = k;debug(n);
        int res = 0;
        int flag = 0;
        for (int i  = 2; i <= int(sqrt(n) + 1);  i++)
        {
            if (n % i == 0)
            {
                a = i;
                res = n / i;
                for (int j = i + 1; j <= int(sqrt(res) + 1); j++)
                {
                    if (res % j == 0)
                    {
                        b = j;
                        c = res / j;
                        if (b < c && a < c)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (flag == 1)
                break;
        }
        if (flag)
        {
            puts("YES");
            cout << a << ' ' << b << ' ' << c << endl;
        }
        else
        {
            puts("NO");
        }
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

