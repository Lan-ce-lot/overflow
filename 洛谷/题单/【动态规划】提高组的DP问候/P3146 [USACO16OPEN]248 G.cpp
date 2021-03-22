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
ll t, n, f[1005][1005], a[maxn], s[maxn], c[maxn];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		c[i] = a[i] = read();
		
		s[i] = s[i - 1] + a[i];
	}int ans = 0;
	for (int i = 1; i <= n; i++) f[i][i] = a[i];
	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				if (f[l][k] == f[k + 1][r] && f[l][k] != 0 && f[k+1][r] != 0) {
					f[l][r] = max(f[l][r], f[l][k] + 1);ans = max(ans * 1ll, f[l][r]);
				}
			}
		}
	}
	
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

