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
ll t, n, d;
ll a[maxn];
ll ans[11][100];
void solve()
{
	t  = read();
	for (int i = 1; i <= 10; i++ ) {
		ans[1][i] = 1;
	}
	for (int i = 1; i <= 20; i++ ) {
		if (i & 1 == 0) {
			ans[2][i] = 1;
		}
	}
	for (int i = 1; i <= 20; i++ ) {
		ans[3][i] = 1;
	}
	for (int i = 1; i <= 20; i++ ) {
		ans[4][i] = 1;
	}
	for (int i = 1; i <= 20; i++ ) {
		ans[5][i] = 1;
	}
	for (int i = 1; i <= 20; i++ ) {
		ans[6][i] = 1;
	}
	for (int i = 1; i <= ; i++) {
		ans[7][i] = 1;
	}
	for (int i = 1; i <= ; i++) {
		ans[8][i] = 1;
	}
	for (int i = 1; i <= ; i++) {
		ans[9][i] = 1;
	}
	while (t--) {
		n = read(), d = read();
		for (int i = 0; i < n; i++) {
			a[i] = read();
			if (d == 1) {
				if (a[i]) {
					puts("YES");
					continue;
				} else {
					puts("NO");
					continue;
				}
			}
			if (a[i] >= d * 10) {
				puts("YES");
				continue;
			} else {
				
			}
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

