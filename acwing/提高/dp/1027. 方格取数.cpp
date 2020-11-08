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
int t, n, a, b, c;
int ma[1005][1005], dp[105][105][100];
void solve()
{
	cin >> n;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) {
			break;	
		}
		ma[a][b] = c;
	}
	for (int k = 2; k <= n * 2; k++) {
		for (int i1 = 1; i1 <= n; i1++) {
			for (int i2 = 1; i2 <= n; i2++) {
				int j1 = k - i1, j2 = k - i2;
				if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
					int &x = dp[k][i1][i2];
					int t = ma[i1][j1];
					if (i1 != i2) t += ma[i2][j2];
					x = max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
					x = max(x, dp[k - 1][i1 - 1][i2] + t);
					x = max(x, dp[k - 1][i1][i2 - 1] + t);
					x = max(x, dp[k - 1][i1][i2] + t);
				}
			}
		}
	}
	cout << dp[n * 2][n][n] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

