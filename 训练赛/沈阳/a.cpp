//#include <bits/stdc++.h> // 3 99 49 50 50 50 100 100
#include<queue>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>
#define E (2.71828182)
#define PI (3.1415926535898)
#define mod 1000000007
#include<set>
#include<map>
#define gc getchar
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
const long long  MAX = 300, INF = 0x3f3f3f3f3f3f3f3f, MOD = 2015;

ll dp[1005][10005], v[1005], w[1005], n, m, W = 10000;
void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < 1005; i++)
        dp[i][0] = 0;
    while(scanf("%lld %lld", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%lld %lld", v + i, w + i);
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= W; j++)
            {
                if (j < w[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        ll x, c = INF;
        for (int i = W; i >= m; i--)
        {
            c > dp[n][i] ? c = dp[n][i], x = i : 0 ;
        }
        printf("%lld %lld\n", c, x);
    }
}
int main()
{
    solve();
}
