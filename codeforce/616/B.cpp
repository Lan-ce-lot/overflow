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
const int maxn = 300005;

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
        n = read();
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = read();
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] < i && a[i] < (n - i - 1))
            {
                puts("NO");
                flag = 1;
                break;
            }

        }
        if (!(n & 1))
        {
            if (a[n / 2] == a[n / 2 - 1] && a[n / 2 - 1] == n / 2 - 1)
            {
                puts("NO");
                flag = 1;

            }
        }

        if (flag == 0)
            puts("YES");

    }
}

int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

