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
int a[maxn];
ll qpow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod; 
		n >>= 1;
		
	}
 	return res % mod;
}

void solve()
{
	t = read();
	while (t--) {
		n = read();
		ll ans_b = 0, ans_j = 0;
		int maxx = -INF, minn = INF, max_c = 0, min_c = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			maxx = max(a[i], maxx), minn = min(a[i], minn);
			
		}
		
		int l, r;
		l = r = n;
		for (int i = n; i >= 1; i--) {
			if (a[i] == maxx) {
				l = i - 1;
				max_c++;
				
			} 
			if (a[i] == minn) {
				r = i - 1;
				min_c++;
			}
			ans_b = (ans_b + n - max(l, r)) % mod;
		}
//		ans_j = max_c * min_c * (1 << (n - 2));
		if (maxx == minn) {
			ans_j = (qpow(2, n) + mod - 1) % mod;
		} else {
			ans_j = (qpow(2, max_c) + mod - 1) % mod * ((qpow(2, min_c) + mod - 1) % mod) % mod * qpow(2, n - max_c - min_c) % mod;
		}
		printf("%lld %lld\n", ans_b, ans_j);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

