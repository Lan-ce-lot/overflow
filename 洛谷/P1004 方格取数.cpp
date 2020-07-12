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
const int maxn = 12;
struct node
{
    int x, y, lx, ly;
} a[maxn];
int dp[maxn][maxn];
int pre[maxn][maxn], n, m, xx, yy, i, j, jj, c;
int mazz[11][11];
int main()
{
    scanf("%d", &n);
    while (1)
	{
		scanf("%d%d%d", &i, &j, &c);
		if (!i && !j && !c)
			break;
		mazz[i][j] = c;
	}
    int step = 2 * n - 2;
    
    for (int s = 0; s <= step; s++)
    {
        for (int i = s + 1; i >= 1; i--)
        {
            for (int ii = s + 1; ii >= 1; ii--)
            {
                j = s - i + 2;
                jj = s - ii + 2;
                dp[i][ii] = max(max(dp[i][ii], dp[i - 1][ii -1]), max(dp[i][ii - 1], dp[i -1][ii])) + mazz[i][j];
                dp[i][ii] +=mazz[ii][jj] * (i != ii);

            }
        }
    }
    printf("%d\n", dp[n][n]);
    return 0;
}

