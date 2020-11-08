/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
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
int t, n, x;
ll w[1005], l[1005], dp[1005][1005], res[1005];
void solve()
{
	n = read(), x = read();
	for (int i = 1; i <= n; i++) {
		l[i] = read(), w[i] = read(), res[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j] + l[i];
			if (j >= res[i])
			dp[i][j] = max(dp[i - 1][j] + l[i], dp[i - 1][j - res[i]] + w[i]);
		}
	}
	cout << dp[n][x] * 5ll << endl;
}
//	for (int i = 1; i <= n; i++) {
//		for (int j = x; j >= res[i]; j++) {
//			dp[j] = max(dp[j], dp[j - res[i]] + w[i]);
//		}
//		for (int j = res[i] - 1; j >= 0; j--) {
//			dp[j] += l[i];
//		}
//	}
//	cout << dp[n] << endl;
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

