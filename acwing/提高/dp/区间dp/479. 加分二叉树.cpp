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
int t, n;
int a[maxn];
int dp[30][30];
int g[30][30];

void dfs(int l, int r) {
	if (l > r) return ;
	
	int k = g[l][r]; 
	cout << k << ' ';
	dfs(l, k - 1);
	dfs(k + 1, r);
}

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int len = 1; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			
			if (len == 1) {
				dp[l][r] = a[l];
				g[l][r] = l;
			} else {
				for (int k = l; k <= r; k++) {
					int le = k == l ? 1 : dp[l][k - 1];
					int ri = k == r ? 1 : dp[k + 1][r];
					
					int s = le * ri + a[k];
					if (dp[l][r] < s) {
						dp[l][r] = s;
						g[l][r] = k;
					}
				}
			}
		}
	}
	cout << dp[1][n] << endl;
	dfs(1, n);

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

