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
const int mod = 1e4 + 7;
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
int t, a, b, k, n, m, ans;
ll qpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}
ll yh[1005][1005];
void init() {
	yh[2][1] = 1, yh[2][2] = 1;
	for (int i = 3; i <= 1004; i++) {
		for (int j = 1; j <= i; j++) {
			yh[i][j] = (yh[i - 1][j] + yh[i - 1][j - 1]) % mod;
		}
	}
}
void solve()
{
//	debug(mod);
/*
1
1 1
1 2 1

*/

	init();
	a = read(), b = read(), k = read(), n = read(), m = read();
	ll l = min(n, m) + 1;
//	debug(l);
	cout << (qpow(a, n) * qpow(b, m)) % mod * yh[k + 1][l] % mod << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

