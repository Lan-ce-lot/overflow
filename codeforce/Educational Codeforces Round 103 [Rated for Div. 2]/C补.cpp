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
ll t, n;
ll a[maxn], b[maxn], c[maxn], ans = 0;
void solve()
{
	t = read();
	while (t--) {
		n = read();
		ans = 0;
		for (int i = 0; i < n; i++) {
			c[i] = read();
		}
		for (int i = 0; i < n; i++) {
			a[i] = read();
		}
		for (int i = 0; i < n; i++) {
			b[i] = read();
		}
		ll tmp = 0;
		for (int i = 1; i < n; i++) {
			if (i == 1) {
				// self
				// +before
				tmp += abs(a[i] - b[i]) + 1 + c[i];
			} else {
				if (a[i] != b[i]) {
					tmp = max(abs(a[i] - b[i]) + 1 + c[i], tmp + c[i] -  abs(a[i] - b[i]) + 1);
				} else {
					tmp = abs(a[i] - b[i]) + 1 + c[i];
				}
			}
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

