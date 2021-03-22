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
ll t, n, f[1005][1005], m[1005][1005];
ll nu[maxn], ind1 = 1, ind2 = 1, ans = -INF;
char c[maxn];
vector<int> A;
void solve()
{
	n = read();	
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> nu[i];
		c[i + n] = c[i];
		nu[i + n] = nu[i];
	}
	int mm = 2 * n - 1;
	for (int i = 1; i <= mm; i++) f[i][i] = m[i][i] = nu[i];
	for (int len = 2; len <= mm; len++) {
		
		for (int l = 1; l + len - 1 <= mm; l++) {
			int r = l + len - 1;
			f[l][r] = -INF;
			m[l][r] = INF;
			for (int k = l; k < r; k++) {
				if (c[k + 1] == 't') {
					f[l][r] = max(f[l][k] + f[k + 1][r], f[l][r]);
					m[l][r] = min(m[l][k] + m[k + 1][r], m[l][r]);
				} else {
					f[l][r] = 
					max(f[l][r], 
					max(f[l][k] * f[k + 1][r], 
					max(f[l][k] * m[k + 1][r], 
					max(m[l][k] * f[k + 1][r], 
						m[l][k] * m[k + 1][r]))));
					m[l][r] =
					min(m[l][r], 
					min(f[l][k] * f[k + 1][r], 
					min(f[l][k] * m[k + 1][r], 
					min(m[l][k] * f[k + 1][r], 
						m[l][k] * m[k + 1][r]))));
				}
			}
		}
	}
	ans = -INF;
	for (int i = 1; i <= n; i++) {
		if (ans < f[i][n + i - 1]) {
			ans = f[i][n + i - 1];
			A.clear();
			A.push_back(i);
		} else if (ans == f[i][n + i - 1]) {
			A.push_back(i);
		}
	}
	cout << ans << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ' '; 
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
