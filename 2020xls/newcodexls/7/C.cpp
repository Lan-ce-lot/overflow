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
ll t, n, m, N, K;

void solve()
{
//	N = read(), K = read();
//	
//	ll all = (N % mod * K % mod) % mod;
//	all = all - (K - 2);
//	cout << all << endl;
	// 
	t = read();
	while (t--) {
		n = read();
		m = read();
		ll all = n * m;
		if (n > m) {
			swap(n, m);
		}
		ll s = m / n;
		ll yu = m % n;
		
		ll con = 0;
		if (yu == 0) {
//			cout << m << endl;
			printf("%lld\n", m);
			for (int i = 0; i < m; i++) {
				if (i == 0) {
//					cout << n;
					printf("%lld", n);
				} else {
					printf(" %lld", n);
				}
			}
		} else {
			ll con_1 = (yu * n - yu * yu);
			con = s * n + yu + con_1;
//			cout << con << endl;
			printf("%lld\n", con);
			for (int i = 0; i < s * n; i++) {
				if (i == 0) {
//					cout << n;
					printf("%lld", n);
				} else {
					printf(" %lld", n);
//					cout << ' ' << n;
				}
			}
			for (int i = 0; i < yu; i++) {
//				cout << ' ' << yu;
				printf(" %lld", yu);
			}
			for (int i = 0; i < con_1; i++) {
//				cout << ' ' << 1;
				printf(" 1");
			}

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

