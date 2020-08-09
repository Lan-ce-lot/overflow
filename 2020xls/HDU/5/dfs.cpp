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
int t, n, K;

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
ll rev(ll a) {
	return qpow(a, mod - 2, mod);
}

set<int> tem;
bool vis[maxn];
int con[maxn];
void dfs(int n, string str) {
	if (n <= 1 ) {
		int tt = *tem.begin();
//		debug(tt);
//		cout <<'-' << str << endl;
		con[tt] = (con[tt] + 1) % mod;
		return;
	}
//	for (auto it : tem) cout << it << ' ';
//	puts("");
	int tt = *tem.begin();
	str = str +  char(tt + '0');
//	cout << n << ' ' << tt << endl;
	vis[tt] = 1;
	tem.erase(tt);

	for (int i = 1; i <= K; i++) {
		if (vis[i] == 0) {
			tem.erase(i);
			vis[i] = 1;
			dfs(n - 2, str + char(i + '0'));
			tem.insert(i);
			vis[i] = 0;
		}
	}
	
	vis[tt] = 0;
	tem.insert(tt);
}

void solve()
{
	t = read();
	while (t--) {
		set<int> S;
		
		n = read();
		K = n;
		for (int i = 1; i <= n; i++) {
			S.insert(i);
			vis[i] = 0;
			con[i] = 0;
			tem.insert(i);
		}

		dfs(n, "");
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			cout << con[i] << ' ';
			sum = (sum % mod + con[i] % mod) % mod;
		}
		cout << '>' << sum ;
		puts("");
		ll rr = rev(sum);
		for (int i = 1; i <= n; i++) {
			if (i != 1) printf(" ");
			printf("%lld", con[i] * rr % mod);
		}
		puts("");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

