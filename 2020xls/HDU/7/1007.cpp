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
ll t, n, x, y;
int dir[8][2] = {1, 0, 0, 1, 1, 1, -1, -1, 0, -1, -1, 0, -1, 1, 1, -1};
map<PII, ll> MX;

inline bool test(ll x, ll y) {return  __gcd(x, y) != 1 && (!(MX[{x, y}]));}
vector<PII> A;
ll ans = 0, con = 0;
bool bfs(ll x, ll y) {
	queue<PII> Q;
	Q.push({x, y});
	A.push_back({x, y});
	MX[{x,y}] = 1;
	while (!Q.empty()) {
		PII top = Q.front();
		Q.pop();
		if (top.first == top.second) return 1;
		for (int i = 0; i < 8; i++) {
			ll xx = top.first + dir[i][0], yy = top.second + dir[i][1];
			if (test(xx, yy)) {
				MX[{xx, yy}] = 1;
				Q.push({xx, yy});
				A.push_back({xx, yy});
				ans++;
				if (top.first == x && top.second == y) {
					con++;
				}
			}
		}
	}
	return 0;
} 
ll count(ll x, ll y) {
	ll res = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (__gcd(x + i, y + j) != 1) {
				res++;
			}
		}
	}
	return res;
}
void solve()
{
	t = read();
	while (t--) {
		ans = 1;
		con = 1;
		MX.clear();
		A.clear();
		x = read(), y = read();
		if (bfs(x, y)) {
			puts("0/1");continue;
		}
		ll di = 0;
		for (int i = 0; i < A.size(); i++) {
			PII it = A[i];
			di += count(it.first, it.second);
		}
		con = count(x, y);
		ll gc = __gcd(con, di);
		printf("%lld/%lld\n", con / gc, di / gc);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

