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
int t, n;
int h[maxn], e[maxn], ne[maxn],tot = 0;
bool vis[maxn];
int dp[maxn][2];
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}


void dfs(int u) {
	dp[u][1] = 1, dp[u][0] = 0;
	for (int i = h[u]; i ; i = ne[i]) {
		int j = e[i];
		dfs(j);
		dp[u][0] += dp[j][1];
		dp[u][1] += min(dp[j][0], dp[j][1]);
		
	}
}

void solve()
{
	while (~scanf("%d", &n)) {
		memset(h, 0, sizeof h);
		memset(vis, 0, sizeof vis);
		tot = 1;
		for (int i = 0; i < n; i++) {
			int id, tem;
			scanf("%d:(%d)", &id, &tem);
			while (tem--) {
				int var;
				scanf("%d", &var);
				add(id, var);
				vis[var] = 1;
			}	
		}
		int root = 0;
		while (vis[root]) root++;
		dfs(root);
		printf("%d\n", min(dp[root][0], dp[root][1]));
	} 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

