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
typedef pair<ll, ll> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
#define x first
#define y second
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
//int t, n;
// geng
struct node {
	int x, y;
	bool operator < (const node &w) const {
		if (x != w.x) return x < w.x;
		return y < w.y;
	}
};
int con_c[maxn];
int con_d[maxn];
node C[maxn], D[maxn];
void solve()
{
	ll ans = 0;
	
	ll n = read(), m = read(), c = read(), v = read();
	for (int i = 0; i < n; i++) {
		ll ta = read(), tb = read();
		C[i] = {ta, tb};
		con_c[ta]++;
	}
	
	for (int i = 0; i < m; i++) {
		ll ta = read(), tb = read();
		D[i] = {ta, tb};
		con_d[ta]++;
	}
	sort(C, C + n);
	sort(D, D + m);
	int l = 0, r = 0;
	while (l < m) {
		
		while (C[l].x > D[r].x) {
			r++;
		}
		while (C[l].x < D[r].x) {
			l++;
			ans--;
		}
		if (con_c[C[l].x] < con_d[D[r].x]) {
			
		}
		l++;
	}
	cout << ans << '\n';
	for (int i = 0; i < m; i++) {
		
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

