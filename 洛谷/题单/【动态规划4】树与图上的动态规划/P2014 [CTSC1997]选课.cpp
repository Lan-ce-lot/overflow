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
const int maxn = 100005;
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
vector<int> G[maxn];
int wight[maxn];
int dp[1000][1000];

void dfs(int u, int tot) {
	if (tot <= 0) return;
	for (int i = 0; i < G[u].size(); i++) {
		int tem = G[u][i];
		
		for (int j = 0; j < tot; j++) {
			dp[tem][j] = dp[u][j] + wight[tem];
		}
		dfs(tem, tot - 1);
		for (int j = 1; j <= tot; j++) {
			dp[u][j] = max(dp[u][j], dp[tem][j - 1]);
		}
	}
}

void solve()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		ll a = read(), b = read();
		
		wight[i] = b;
		G[a].push_back(i);
	}
	dfs(0, m);
	 
	printf("%d\n", dp[0][m]);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

