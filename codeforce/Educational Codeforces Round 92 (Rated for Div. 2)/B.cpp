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
const int maxn = 1e5 + 5;
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
int t, n, k, z;
ll a[maxn];
ll dp[maxn][2];
ll sum[maxn];
void solve()
{
	cin >> t;
	while (t--) {
		n = read(), k = read(), z = read();
		for (int i = 1; i <= n; i++) {
			sum[i] = 0;
			a[i] = read();
			sum[i] = sum[i - 1] + a[i];
		}
		int con = 0;
		ll ans = -INF;
		for (int i = 1; i <= k + 1; i++) {
			ll tem;
			if (k + 1 - i > 2) {
				tem = sum[k - z * 2 + i] + (z) * (a[i] + a[i + 1]);
			} else {
				tem = sum[k - z * 2 + i] + (z) * a[i];
			}
			 
			debug(tem);
			 if (ans <= tem) {
			 	ans = tem;
			 }
		}
		cout << ans << '\n';
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

