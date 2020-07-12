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
int n, V;
int dp[maxn], v[maxn], w[maxn], c[maxn];

int main()
{
    n = read();
    V = read();
    for (int i = 1; i <= n; i++)
    {
        v[i] = read();
        w[i] = read();
        c[i] = read();
    }



    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j > 0; j--)
        {
            for (int k  = 0; k <= c[i]; k++)
            {
                if (k * v[i] <= j)
                {
                    dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= V; j++)
        cout << dp[i] << ' ';
    cout << dp[V] << endl;
    return 0;
}

