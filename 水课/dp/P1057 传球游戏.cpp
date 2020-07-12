/*************************************************************************
 > File Name:
 > Author:
 > Mail: lancelot_hcs@qq.com
 > Time: 9102
 > Desc:
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

ll dp[maxn][maxn], n, m, ans = 0, t;
int main()
{
    cin >> n >> t;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][n];
            }
            else if (j == n)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i -1][1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    cout << dp[t][1] <<endl;
	return 0;
}
