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
const int maxn = 1000005, M = 35;
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
int a[maxn], tail[maxn];
ll dp[1005][1005][M];

void add(ll a[], ll b[]) {
	static ll c[M];
	memset(c, 0, sizeof c);
	for (int i = 0, t = 0; i < M; i++) {
		t += a[i] + b[i];
		c[i] = t % 10;
		t /= 10;
	} 
	memcpy(a, c, sizeof c);
}

void mul(ll a[], ll b) {
	static ll c[M];
	memset(c, 0, sizeof c);
	ll t = 0;
	for (int i = 0; i < M; i++) {
		t += a[i] * b;
		c[i] = t % 10;
		t /= 10;
	}
	memcpy(a, c, sizeof c);
}

int cmp(ll a[], ll b[]) {
	for (int i = M - 1; i >= 0; i--) {
		if (a[i] > b[i]) return 1;
		else if (a[i] < b[i]) return -1;
	}
	return 0;
}

void print(ll a[]) {
	int k = M - 1;
	while (k && !a[k]) k--;
	while (k >= 0) cout << a[k--];
	cout << endl;
}


ll tem[M];
void solve()
{
	n = read();
	
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	} 
	for (int i = 1; i <= n; i++) {
		tail[i] = a[i - 1];
	}tail[1] = a[n];
	for (int i = 1; i <= n * 2; i++) {
		a[i + n] = a[i];
		tail[i + n] = tail[i];
	}
	
	for (int len = 3; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			dp[l][r][M - 1] = 1;
			for (int k = l + 1; k < r; k++) {
				memset(tem, 0, sizeof tem);
				tem[0] = a[l];
				mul(tem, a[k]);
				mul(tem, a[r]);
				add(tem, dp[l][k]);
				add(tem, dp[k][r]);
				if (cmp(dp[l][r], tem) > 0)
					memcpy(dp[l][r], tem, sizeof tem);
				
//				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r] + a[l] * a[i] * a[r]);
			}
		}
	}
//	int res = INF;
//	for (int i = 1; i <= n; i++) {
//		res = min(res, dp[i][i + n]);
//	}
//	cout << dp[1][n];
	print(dp[1][n]);
	
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

