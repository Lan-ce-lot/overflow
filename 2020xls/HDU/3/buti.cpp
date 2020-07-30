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
const int mod = 1000000007;
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
int t, n;
ll a[maxn];
ll par[maxn];
ll con_1[maxn];
ll con_2[maxn];
ll find(ll x) {
	if (x == par[x]) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
} 

void unite(ll x, ll y) {
	x = find(x), y = find(y);
	if (x != y) {
		par[x] = y;
		con_1[y] += con_1[x];
		con_2[y] += con_2[x];
	}
}

void solve()
{
	cin >> t;
	while (t--) {
		ll co_1 = 0, co_2 = 0;
		n = read();
		for (int i = 0; i <= maxn; i++) {
			par[i] = i;
			con_1[i] = 0;
			con_2[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			
			if (a[i] == 1) {
				con_1[i]++;
				co_1++;
			} else {
				con_2[i]++;
				co_2++;
			}
		}
		ll ans = co_2 * (co_2 - 1) * (co_2 - 2) / 6 +  co_2 * (co_2 - 1) * co_1 / 2;
		ans = (ans % mod + mod) % mod;
		printf("%lld\n", ans % mod);
		
		
		for (int i = 0; i < n - 1; i++) {
			ll l, r;
			l = read(), r = read();
			l = find(l), r = find(r);
			ans -= con_1[l] * con_2[r] * (co_2 - con_2[l] - con_2[r]); // 12 122
			ans -= con_2[l] * con_2[r] * (co_2 - con_2[l] - con_2[r]); // 22 222
			ans -= con_2[l] * con_2[r] * (co_1 - con_1[l] - con_1[r]); // 22 221
			ans -= con_2[l] * con_1[r] * (co_2 - con_2[l] - con_2[r]); // 21 212
			
			unite(l, r);
			ans = (ans % mod + mod) % mod;
			printf("%lld\n", ans % mod);
			
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

