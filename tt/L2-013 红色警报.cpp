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
int t, n, m, k, a;
bool vis[505], dis[505];
int h[maxn], e[maxn], tot, ne[maxn];
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}
int con = 0, now = 0;
void dfs(int u) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int to = e[i];
		if (vis[to] == 0 && dis[to] == 0) {
			vis[to] = 1;
			dfs(to);
		}
	}
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	now = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0 && dis[i] == 0) {
			vis[i] = 1;
			dfs(i);
			now++;
		}
	} 
	memset(vis, 0, sizeof vis);
	cin >> k;
	for (int i = 1;i <= k; i++) {
		cin >> a;
		con = 0;
		vis[a] = 1, dis[a] = 1;
		memset(vis, 0, sizeof vis);
		for (int j = 0; j < n; j++) {
			if (vis[j] == 0 && dis[j] == 0) {
				vis[j] = 1;
				dfs(j);
				con++;
			}
		}

		if (con <= now) {
			printf("City %d is lost.\n", a);
		} else {
			printf("Red Alert: City %d is lost!\n", a);
		}
		now = con;
		if (i == n) {
			puts("Game Over.");
			return;
		}
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

