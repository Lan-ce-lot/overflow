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
int t, n, m;

int p[maxn], w[maxn], sum[maxn], f[55][55][2];
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> w[i];
		sum[i] = sum[i - 1] + w[i];
	}
	memset(f, 0x3f, sizeof f);
	f[m][m][0] = f[m][m][1] = 0;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			f[l][r][0] = min(
			f[l + 1][r][0] + (p[l + 1] - p[l]) * (sum[l] + sum[n] - sum[r]), 
			f[l + 1][r][1] + (p[r] - p[l]) * (sum[l] + sum[n] - sum[r]));

			f[l][r][1] = min(
			f[l][r - 1][0] + (p[r] - p[l]) * (sum[l - 1] + sum[n] - sum[r - 1]), 
			f[l][r - 1][1] + (p[r] - p[r - 1]) * (sum[l - 1] + sum[n] - sum[r - 1]));
		}
	} 
	cout << min(f[1][n][0], f[1][n][1]);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

