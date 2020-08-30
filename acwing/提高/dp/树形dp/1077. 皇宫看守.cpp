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
const int maxn = 1505;
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
int t, n, cost[maxn];
int dp[maxn][3];
int h[maxn], ne[maxn], e[maxn], idx = 1;
bool vis[maxn];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
	
	dp[u][2] = cost[u];
	for (int i = h[u]; i ;i = ne[i]) {
		int j  = e[i];
		dfs(j);
		
		dp[u][0] += min(dp[j][1], dp[j][2]);// fu
		dp[u][2] += min(dp[j][0], min(dp[j][1], dp[j][2]));// fang
	}
	dp[u][1] = INF;
	for (int i = h[u]; i ;i = ne[i]) {
		int j = e[i];
		dp[u][1] = min(dp[u][1], dp[j][2] + dp[u][0] - min(dp[j][1], dp[j][2]));// 当前的，dp[u][0]加了的要减掉 
	}
	
}


void solve()
{
	n = read();
	memset(h, 0, sizeof h);
	idx = 1;
	for (int i = 1; i <= n; i++) {
		int id = read();
		cost[id] = read();
		int con = read();
		for (int j = 1; j <= con; j++) {
			int tem = read();
			add(id, tem);
			vis[tem] = 1;
		}
	}
	int root = 1;
	while (vis[root]) root ++;
	
	dfs(root);
	printf("%d\n", min(dp[root][1], dp[root][2]));
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

