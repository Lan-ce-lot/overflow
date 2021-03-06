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
ll ans[maxn];
ll sum[maxn];

ll qpow(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}
ll C(ll a, ll b) {
	ll res = 1;
	for (int i = 1, j = a; i <= b; i++, j--) {
		res = res * j % mod;
		res = res * qpow(i, mod - 2) % mod;
	}
	return res;
}

ll lucas(ll a, ll b) {
	if (a < mod && b < mod) return C(a,b);
	return C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;
}

void solve()
{
	n = read();
	ans[2] = 1;
	sum[2] = 1;
	
	for (int i = 3; i <= n; i++) {
		ll tmp = ((lucas(i, 2) * qpow(26, i - 2) % mod - qpow(2, i - 2)) % mod + mod) % mod;
		ans[i] = (ans[i - 1] + tmp) % mod;
		
	}
	cout << ans[n] << endl;
}


int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

