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
int t, n;
int a[maxn], dp[1005][1005];
int dp1[1005][1005];
int sum[maxn]; 
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		a[i + n] = a[i];
	}
	
	for (int i = 1; i <= n * 2; i++) sum[i] = sum[i - 1] + a[i];
	
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n * 2; l++) {
			int r = l + len - 1;
			dp[l][r] = INF;
			dp1[l][r] = -INF;
			for (int i = l; i < r; i++) {
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + sum[r] - sum[l - 1]);
				dp1[l][r] = max(dp1[l][r], dp1[l][i] + dp1[i + 1][r] + sum[r] - sum[l - 1]);
			}
		} 
	}
	int minv = INF, maxv = -INF;
	for (int i = 1; i <= n; i++) {
		minv = min(minv, dp[i][i + n - 1]);
		maxv = max(maxv, dp1[i][i + n  - 1]);
	}
	cout << minv << endl << maxv << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

