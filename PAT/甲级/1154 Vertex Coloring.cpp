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
int t, n, m, q, flag = 0;
vector<int> G[maxn]; 
int no[maxn];
set<int> S;
bool vis[maxn];
void dfs(int u, int fa) {
	if (fa != -1 && (flag || no[u] == no[fa])) {
		flag = 1;
		return;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (!vis[to]) {
			vis[to] = 1;
			dfs(to, u);
			vis[to] = 0;
		}
	}
}
vector<PII> E;
void solve()
{
	n = read(), m = read();
	for (int i = 0; i < m; i++) {
		int a = read(), b = read();
		E.push_back({a, b});
	}
	q = read();
	while (q--) {
		flag = 0;
		S.clear();
		for (int i = 0; i < n; i++) {
			no[i] = read();
			S.insert(no[i]);
		}
		for (int i = 0; i < m; i++) {
			if (no[E[i].first] == no[E[i].second]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			puts("No");
		} else {
			cout << S.size();
			puts("-coloring");
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

