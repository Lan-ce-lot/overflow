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
int t, n, a[maxn], dp[1005][1005], dp1[1005][1005];
int sum[maxn];
// f[i][j] = max(f[i][k] + f[k+1][j] + d(i,j))
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		a[i + n] = a[i];
//		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n * 2; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n * 2 ; l++) {
			int r = l + len - 1;
			dp[l][r] = -INF;
			dp1[l][r] = INF;
			for (int k = l; k < r; k++) {
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
				dp1[l][r] = min(dp1[l][r], dp1[l][k] + dp1[k + 1][r] + sum[r] - sum[l - 1]);
			}
		}
	}
	int maxx = -INF, minn = INF;
	for (int i = 1; i <= n; i++){
		minn = min(minn, dp1[i][i + n - 1]);
		maxx = max(maxx, dp[i][i + n - 1]);
	}
	cout << minn << '\n' << maxx << '\n'; 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

