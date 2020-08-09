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
ll dp[4000];
bool vis[maxn];
ll ans = 0, tot = 0, res;
void dp_() {
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	ans = 0;
	tot = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		for (int j = tot; j >= 0; j--) {
			if (dp[j]&&!dp[j+a[i]]) dp[j+a[i]]=1,ans++;
		}
		tot+=a[i];
	}
	res = max(ans, res);
}

void dfs(int height, int last) {
	if (last > m) {
		return;
	}
	if (height == n) {
		if (last == m) {
			dp_();
		}
		return;
	}
	dfs(height + 1, last);
	vis[height + 1] = 1;
	dfs(height + 1, last + 1);
	vis[height + 1] = 0;
}


void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	
	dfs(0, 0);
	
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

