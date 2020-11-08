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
#define x first
#define y second
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
int t, n, q, sum = 0;
//int G[105][105];
int dp[105][105];
vector<PII> G[maxn];
void dfs(int x, int fa) {

	for (int i = 0; i < G[x].size(); i++) {
		int tem_x = G[x][i].x;
		int tem_y = G[x][i].y;
		
		if (tem_x != fa) {
//			dp[x][tem_x] = tem_y;
//			dp[tem_x][x] = tem_y;
			dfs(tem_x, x);
			for (int j = q; j; j--) {
				for (int k = 0; k + 1 <= j; k++) {
					dp[x][j] = max(dp[x][j], dp[x][j - k - 1] + dp[tem_x][k] + tem_y);
				}
			}
//			dp[x][fa] += dp[tem_x][x];
//			dp[fa][x] += dp[tem_x][x];
//			sum += tem_y;
		}
	}
	
}
//vector<int> G[maxn];
void cut (int x, int fa){
	
	for (int i = 0; i < G[x].size(); i++) {
		int tem_x = G[x][i].x;
		int tem_y = G[x][i].y;
		
		if (tem_x != fa) {
			cut(tem_x, x);
		}
	}
}

void pr(int x, int fa) {
	
	
	for (int i = 0; i < G[x].size(); i++) {
		int tem_x = G[x][i].x;
		int tem_y = G[x][i].y;
		if (tem_x != fa) {
//			printf("%d->%d=%d\n", x, tem_x, dp[x][tem_x]);
			pr(tem_x, x);
		}
	}
}


void solve()
{
	n = read(), q = read();
	for (int i = 1; i <= n - 1; i++) {
		int a = read(), b = read(), c = read();
		G[a].push_back({b, c});
		G[b].push_back({a, c});
		
	}
//	for (int i = 1; i <= n; i++) {
//		for (auto it : G[i]) cout << it.x << "->" << it.y << ' ';
//		puts("");
//	}
	
	dfs(1, 0);
	printf("%d\n", dp[1][q]);
//	cout << sum << endl;
//	pr(1, 0);
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

