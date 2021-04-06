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
ll t, n, L, k, a[maxn], pr[maxn];
bool check(ll m) {
	int tot = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (pr[i] > m) {
			tot += pr[i] / m;
			tot -= !(pr[i] % m);
		}
	}
	return tot <= k;
}
void solve()
{
	// 我们把公路上相邻路标的最大距离定义， 
	// 使得公路的“空旷指数”最小
	cin >> L >> n >> k;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		pr[i] = a[i] - a[i - 1];
	} 
	a[n + 1] = L;
	pr[n + 1] = L - a[n];
	ll l = 0, r = 10000005;
	while (l < r) {
		ll m = l + r >> 1;
		if (check(m)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << l << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

