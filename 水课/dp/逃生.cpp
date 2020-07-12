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
const int INF = 10000000;                             //int2147483647//ll9e18//unsigned ll 1e19
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


ll dp[maxn][maxn], n, m, a[maxn][maxn], xx, yy, v, c,ans_1[5],z = 0;
int main()
{
    n = read();
    m = read();
    xx = read();
    yy = read();
    v = read();
    c = read();
	
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);
	memset(dp, 0, sizeof(dp));
    dp[xx][yy] = v;

    for (int i = xx; i <= n; i++)//rd
    {
        for(int j = yy; j <= m; j++)
        {
            if (i == xx && j == yy)
                continue;
            else if (i == xx)
                dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (j == yy)
                dp[i][j] = dp[i - 1][j] + a[i][j]; 
            else   
            	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            if (dp[i][j] > c)
                dp[i][j] = c;
            if (dp[i][j] <= 0)
                dp[i][j] = -INF;
        }
    }
    ans_1[z++] = dp[n][m];

    for (int i = xx; i <= n; i++)//ld
    {
        for(int j = yy; j > 0; j--)
        {
            if (i == xx && j == yy)
                continue;
            else if (i == xx)
                dp[i][j] = dp[i][j + 1] + a[i][j];
            else if (j == yy)
                dp[i][j] = dp[i - 1][j] + a[i][j]; 
            else    
            	dp[i][j] = max(dp[i - 1][j], dp[i][j + 1]) + a[i][j];
            if (dp[i][j] > c)
                dp[i][j] = c;
            if (dp[i][j] <= 0)
                dp[i][j] = -INF;
        }
    }
    ans_1[z++] = dp[n][1];

    for (int i = xx; i > 0; i--)//ru
    {
        for(int j = yy; j <= m; j++)
        {
            if (i == xx && j == yy)
                continue;
            else if (i == xx)
                dp[i][j] = dp[i][j - 1] + a[i][j];
            else if (j == yy)
                dp[i][j] = dp[i + 1][j] + a[i][j]; 
            else    
            	dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) + a[i][j];
            if (dp[i][j] > c)
                dp[i][j] = c;
            if (dp[i][j] <= 0)
                dp[i][j] = -INF;
        }
    }
    ans_1[z++] = dp[1][m];

    for (int i = xx; i > 0; i--)//lu
    {
        for(int j = yy; j > 0; j--)
        {
            if (i == xx && j == yy)
                continue;
            else if (i == xx)
                dp[i][j] = dp[i][j + 1] + a[i][j];
            else if (j == yy)
                dp[i][j] = dp[i + 1][j] + a[i][j];        	
            else  
            	dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + a[i][j];
            if (dp[i][j] > c)
                dp[i][j] = c;
            if (dp[i][j] <= 0)
                dp[i][j] = -INF;
        }
    }
    ans_1[z] = dp[1][1];
    if (max(max(ans_1[0],ans_1[1]), max(ans_1[2],ans_1[3])) < 0)
        cout << -1 << endl;
    else
    printf("%lld\n", *max_element(ans_1, ans_1 + 5));
	return 0;
}
