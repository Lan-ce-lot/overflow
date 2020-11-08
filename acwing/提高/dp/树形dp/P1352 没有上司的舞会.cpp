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
int t, n, ans = 0;
int ha[maxn];
vector<int> G[maxn];
int dp[maxn][2];
int root[maxn];
void dfs(int u) {
	dp[u][1] = ha[u];
	for (int i = 0; i < G[u].size(); i++) {
		int tem = G[u][i];
//		if () 
		dfs(tem);
		dp[u][1] += dp[tem][0];
		dp[u][0] += max(dp[tem][0], dp[tem][1]);
		
	}
}


void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) ha[i] = read();
	for (int i = 1; i < n; i++) {
		int a = read(), b = read();
//		G[a].push_back(b);
		G[b].push_back(a);
		root[a] = b;
	}
	int ro = 1;
	while (root[ro]) {
		ro++;
	}
	dfs(ro);
	cout << max(dp[ro][1], dp[ro][0]) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

