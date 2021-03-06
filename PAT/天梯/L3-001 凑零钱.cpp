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
ll a[maxn];
ll dp[maxn];
bool vis[maxn];
vector<int> V;
bool flag = 0;
void dfs(int now, int mon) {
	if (mon > m || now >= n) {
		
		return;
	}
	if (mon == m) {
		flag = 1;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			V.push_back(a[i]);
			dfs(now + 1,  mon + a[i]);
			vis[i] = 0;
			V.pop_back();
		}
	}
}

void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	
	dfs(0, 0);
	if (!flag) {
		puts("No Solution");
	} else {
		for (auto it : V) {
			cout << it << ' ';
		}
		puts("");
	}
 //	for (int i = 1; i <= n; i++) {
//		for (int j = m; j >= a[i]; j--) {
//			if (dp[j] <= dp[j - a[i]] + a[i]) {
//				dp[j] = dp[j - a[i]] + a[i];
//				vis[i][j] = 1;
//			}
//		}
//	}
//	if (dp[m] != m) {
//		puts("No Solution");
//	} else {
//		int tem_n = n, tem_m = m;
//		for (int i = n; i >= 0; i--) {
//			if () {
//				
//			}
//		}
//	}
	// dp[i][j] = dp[i - 1][j - a[j]];
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

