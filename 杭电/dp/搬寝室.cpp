#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;
const double pi=acos(-1.0);
const int eps=1e-10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn=2005;

int n,m,k,s,dp[maxn][maxn];
int v[maxn], w[maxn];

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++)//
        {
            for (int j = 1; j <= k; j++)//
            {
                dp[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &v[i]);
        }
        sort(v + 1, v + n + 1);

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * 2 <= i; j++)
            {
                dp[i][j] = min(dp[i-2][j - 1] + (v[i] - v[i - 1]) * (v[i] - v[i - 1]), dp[i-1][j]);
            }

        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}

