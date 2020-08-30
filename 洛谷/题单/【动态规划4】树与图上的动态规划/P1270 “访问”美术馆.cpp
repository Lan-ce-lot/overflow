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
int t, n, ind = 0;
int root = 0;
int to[maxn];
int wight[maxn];
int dp[1000][1000];
vector<PII> tem;
vector<int> G[maxn];
struct node{
	int l, r, cost, value;
}N[maxn];
void turn(int u) {
	int a, b;
	scanf("%d%d", &N[u].cost,&N[u].value);
	N[u].l = u << 1, N[u].r = u << 1 | 1;
	
	N[u].cost <<= 1;
	if (N[u].value == 0) {
		turn(u << 1);
		turn(u << 1 | 1);
	}
}

void dfs(int u, int time) {
	if (N[u].value == 0) {
		int l = u << 1, r = u << 1 | 1;
		dfs(N[u].l, time + N[N[u].l].cost);
		dfs(N[u].r, time + N[N[u].r].cost);
		for (int i = 0; i <= t - time; i++) {
			for (int j = 0; time + i + j <= t; j++) {
				dp[u][time + i + j] = max(dp[u][time + j + i], dp[N[u].l][time + i] + dp[N[u].r][time + j]);
			}
		}
	} else {
		for (int i = 1; i <= N[u].value; i++) {
			int now = time + (i * 5);
			if (now > t) break;
			dp[u][now] = dp[u][now - 5] + 1;
		}
	}
	
	
}

void solve()
{
	t = read();// root l r f[x][t] = f[x][t - 5] + 1
	t--;
	int a, b;
	turn(1);
	dfs(1, N[1].cost);
	printf("%d\n", dp[1][t]);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    
    return 0;
}

