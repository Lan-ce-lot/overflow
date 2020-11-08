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
int t, n, m;
int dp[10005][10005];

int dfs(int m, int n) {
	if (n == 0) return 0;
	if (dp[m][n]) {
		return dp[m][n];
	} else {
		return dp[m][n] = dfs(n, m % n) + m / n * n;
	}
}
int flag = 0;
void print(int m, int n) {
	if (n == 0) return;
	int s = m / n;
	int yu = m % n;
	int all = m / n * n;
	for (int i = 0; i < all; i++) {
		if (flag == 0) {
			printf("%d", n);
			flag = 1;
		} else {
			printf(" %d", n);
		}
		
	}
	print(n, m % n);
}

void solve()
{
	scanf("%d", &t);
	while (t--) {
		flag = 0;
		n = read(), m = read();
		if (m < n) swap(m, n);
		ll s = m / n;
		ll yu = m % n;
		if (yu == 0) {
			printf("%d\n", m / n * n);
			for (int i = 0; i < m; i++) {
				if (i == 0) {
					printf("%d", n);
				} else {
					printf(" %d", n);
				}
			}
			puts("");
		} else {
			ll ans = dfs(m, n);
			printf("%lld\n", ans);		
			print(m, n);
			puts("");
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

