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
int t, n, m, v[1005][1005],w[1005][1005], dp[maxn], s[maxn];

void solve()
{
	m = read(), n = read();
	int con = 0;
	for (int i = 1; i <= n; i++) {
		int aa = read(), bb = read(), cc = read();
		v[cc][++s[cc]] = aa, w[cc][s[cc]] = bb;
		con = max(con, cc);
	}
	for (int i = 1; i <= con; i++) {
		for (int j = m; j >= 0; j--) {
			for (int k = 1; k <= s[i]; k++) {
				if (v[i][k] <= j) {
					dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
				}
			}
		}
	}
	cout << dp[m] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

