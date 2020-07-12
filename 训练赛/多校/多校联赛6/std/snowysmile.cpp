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
const int maxn = 21;
int a[maxn], t, count1 = 0, k;
ll xx, yy, m_x, m_y, dp[maxn][maxn];
int dir[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1},{-2, 1},{-1, 2}};
int mark[maxn][maxn];
int main()
{

    scanf("%lld%lld%lld%lld", &xx, &yy, &m_x, &m_y);
    dp[0][0] = 1;
    mark[m_x][m_y] = 1;
    for (int i = 0; i < 8; i++)
        if(m_x + dir[i][0] >= 0 && m_x + dir[i][0] <= xx && m_y + dir[i][1] >= 0 && m_y + dir[i][1] <= yy)
        mark[m_x + dir[i][0]][m_y + dir[i][1]] = 1;
    for (int i = 0; i <= xx; i++)
    {
        for (int j = 0; j <= yy; j++)
        {
            if (i == 0 && j == 0)continue;
            if (i == 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            else
                dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
            dp[i][j]*=!mark[i][j];
        }
    }
    printf("%lld\n", dp[xx][yy]);
    return 0;
}
