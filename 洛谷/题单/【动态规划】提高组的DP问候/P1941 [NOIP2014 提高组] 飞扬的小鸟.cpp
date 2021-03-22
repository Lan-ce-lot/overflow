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
int t, n, m, k, ans = 0;
int h[maxn][2];// 0- 1+
int f[10005][1005], dow[maxn], up[maxn];
void solve() {
	n = read(), m = read(), k = read();
	for (int i = 0; i < n; i++) {
		h[i][0] = read(), h[i][1] = read();
	} 
	for (int i = 1; i <= n; i++) dow[i] = 0, up[i] = m + 1;
	for (int i = 1; i <= k; i++) {
		int p = read(), l = read(), h = read();
		dow[p] = l, up[p] = h;
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= m; j++) 
			f[i][j] = INF;
	f[0][0] = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= h[i - 1][0]) {
				f[i][j] = min(f[i][j], f[i - 1][j - h[i - 1][0]] + 1);
				f[i][j] = min(f[i][j], f[i][j - h[i - 1][0]] + 1);
			}
			if (j == m) {
				for (int k = j - h[i - 1][0]; k <= m; k++) {
					f[i][j] = min(f[i][j], f[i - 1][k] + 1);
					f[i][j] = min(f[i][j], f[i][k] + 1);
				}
			}
		}
		for (int j = dow[i] + 1; j <= up[i] - 1; j++) if (j + h[i - 1][1] <= m)
			f[i][j] = min(f[i][j], f[i - 1][j + h[i - 1][1]]);
		for (int j = 1; j <= dow[i]; j++) f[i][j] = INF;
		for (int j = up[i]; j <= m; j++) f[i][j] = INF; 
	}
	int cnt = k, ans = INF;
	for (int i = n; i >= 1; i--) {
		for (int j = dow[i] + 1; j <= up[i] - 1; j++)
			if (f[i][j] < INF) 
				ans = min(ans, f[i][j]);
		if (ans != INF) break;
		if (up[i] <= m) cnt--;
	}
	if (cnt == k) printf("1\n%d\n", ans);
	else printf("0\n%d\n", cnt);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

