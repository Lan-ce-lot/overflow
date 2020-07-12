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
const int maxn = 10005;

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
int N, V;
int dp[maxn], s[1001], v[maxn], w[maxn];
int a[25000], b[25000], t = 0;
int main()
{
    cin >> N >> V;
    for (int i = 0; i < N; i++)
        cin >> v[i] >> w[i] >> s[i];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < s[i]; j <<= 1)
        {
            a[t] = w[i] * j;
            b[t++] = v[i] * j;
            s[i] -= j;
        }
        if (s[i])
        {
            a[t] = s[i] * w[i];
            b[t++] = s[i] * v[i];
        }
    }
    for(int i=0; i<t; i++) //01±³°ü
        for(int j=V; j>=b[i]; j--)
        {
            dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
        }

    cout << dp[V];
    return 0;
}

