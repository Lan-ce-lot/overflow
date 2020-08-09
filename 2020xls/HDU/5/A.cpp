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
const int mod = 998244353;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 6000005;
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

// 3 * n ^ 2£¬(1-n)³öÏÖ / n ^ 3

ll qpow(ll x, ll n, ll p) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = res * x % p;
		}
		x = x * x % p;
		n >>= 1;
	}
	return res;
}
ll tem[maxn];
ll rev(ll a) {
	return qpow(a, mod - 2, mod);
}




void solve()
{
	t = read();
	for (int i = 1; i <= 6000005; i++) {
		tem[i] = (tem[i - 1] + (3 * (rev(qpow(i, 2, mod))))% mod) % mod;
	}
	while (t--) {
		n = read();
		ll ans = (tem[n] % mod * rev(n) % mod) % mod;
		printf("%lld\n", ans);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

