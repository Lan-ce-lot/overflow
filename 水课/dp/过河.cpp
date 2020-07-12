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

ll dp[10010], n, m, a[100005],ans = 0;

int main()
{
	n = read();
	for (int i = 0; i < n; i++)
		a[i] = read();
	sort(a, a + n);
	int res = a[0], ans = 0;
	dp[1] = a[1];
	dp[0] = a[0];
	for(int i = 2; i < n; i++)
	{
		dp[i] = min(dp[i - 1] + a[i] + a[0],dp[i - 2] + a[0] + 2 * a[1] + a[i]);
	}
	cout << dp[n - 1] << endl;
	return 0;
}
