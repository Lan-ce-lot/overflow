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
const int mod = 1e3;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;


int dp[10010][maxn], n, m, a[maxn][maxn],ans = 0;
int pre[maxn][maxn];
int main()
{
	cin >> n >> m;
	pre[1][1] = a[1][1];
	for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >>a[i][j];
            if(i != 0 || j != 0)pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a[i][j];
//            cout << pre[i][j] << endl;
        }

    }
    for (int i = 1;i <= n; i++)
    {
        for (int j = ;; j++)
        {
            dp[i][j] = max(max(dp[i][j-1] + ,dp[i - 1][j] + ),a[i][j])
        }

    }
    cout << dp[n][m] << endl;
	return 0;
}
