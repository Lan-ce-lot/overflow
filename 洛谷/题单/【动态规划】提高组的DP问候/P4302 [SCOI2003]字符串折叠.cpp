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
int t, n, f[105][105], e[maxn];
string S, s[105][105];
bool check(int l, int r, int len) {
	for (int i = l; i <= r; i++) {
		if (S[i] != S[(i - l) % len + l]) {
			return 0;
		}
	}
	return 1;
}

void solve()
{
	cin >> S;
	n = S.size();
	S= ' ' + S;
	for (int i = 1; i < 10; i++) e[i] = 1;
	for (int i = 10; i < 100; i++) e[i] = 2;
	e[100] = 3;
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			f[l][r] = INF;
			for (int k = l; k < r; k++) {
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
			}
			for (int k = l; k < r; k++) {
				int l_ = k - l + 1;
				if (len % l_ != 0) continue;
				if (check(l, r, l_)) {
					f[l][r] = min(f[l][r], f[l][k] + 2 + e[len / l_]);
				}
			}
		}
	}
	cout << f[1][n] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

