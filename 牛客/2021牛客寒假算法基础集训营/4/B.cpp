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
ll x[maxn], e[maxn];
ll qpow (ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res *= x;
			res %= mod; 
		}
		x *= x;
		x %= mod;
		e >>= 1;
	} 
	return res;
}

void solve()
{
	n = read();
	for (int i = 0; i < n; i++) {
		x[i] = read();
	}
	for (int i = 0; i < n; i++) {
		e[i] = read();
	}
	ll ans = qpow(x[0], e[0]) % mod;
	for (int i = 0; i < n; i++) {
		ans = __gcd(ans % mod, qpow(x[i], e[i]) % mod) % mod;
	}
	cout << ans << endl;
}
/*

100000007
2
10000 10
1 4
10^ 4
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

