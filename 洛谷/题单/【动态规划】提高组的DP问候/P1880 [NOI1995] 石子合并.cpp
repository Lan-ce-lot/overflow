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
int t, n, a[maxn], f[1005][1005], pre[maxn], m[1005][1005];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		a[i + n] = a[i];
	}
	for (int i = 1; i <= n * 2; i++)  
		pre[i] = a[i] + pre[i - 1];
	// 1 2 3 4
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n * 2; l++) {
			int r = l + len - 1;
			m[l][r] = INF;
			f[l][r] = -INF;
			for (int k = l; k < r; k++) {
				f[l][r] = max(f[l][k] + f[k + 1][r] + pre[r] - pre[l - 1], f[l][r]);
				m[l][r] = min(m[l][k] + m[k + 1][r] + pre[r] - pre[l - 1], m[l][r]);
			} 
		}
	}
	int ans1 = INF, ans2 = -INF;
	
	for (int i = 1; i <= n; i++) {
		ans1 = min(ans1, m[i][i + n - 1]);
		ans2 = max(ans2, f[i][i + n - 1]);
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

