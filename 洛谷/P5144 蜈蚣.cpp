/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
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
int a[maxn];
int dp[maxn][maxn];
int pre[maxn][maxn], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i<= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        pre[i][i] = a[i];
        for(int j = i + 1; j <= n; j++)
        {
            pre[i][j] = pre[i][j - 1] ^ a[j];
        }
    }
    for (int i = 1; i <= n; i++)dp[1][i] = pre[1][i];
    for (int i = 2; i <= m; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = i - 1; k < j; k++)
            {
                dp[i][j] = max(dp[i - 1][k] + pre[k + 1][j], dp[i][j]);//Ñ°ÕÒ×î´óµÄ,[i - 1, j]
            }

        }

    }
    cout << dp[m][n]<<endl;
    return 0;
}

