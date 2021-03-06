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
int t, n, m, ans = 0, to, from;
bool vis[3005]; 
vector<int> G[3005];
set<int> node;
bool flag = 0;
void dfs(int u) {
	if (u == to) {
		flag = 1;
		return ;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (vis[to] == 0) {
			vis[to] = 1;
			dfs(to);
			vis[to] = 0;
		}
	}
}


void solve()
{
	n = read(), m = read();
	for (int i = 0; i < m; i++) {
		int a = read(), b = read();
		G[a].push_back(b);
		G[b].push_back(a);
		node.insert(a);
		node.insert(b);
	}
	from = read(), to = read();
	for (auto it : node) {
		memset(vis, 0, sizeof vis);
		if (it == to || it == from) {
			continue;
		}
		vis[it] = 1;
		flag = 0;
		vis[from] = 1;
		dfs(from);
		vis[from] = 0;
		if (flag == 0) {
			ans++;
		}
		vis[it] = 0;
	}
	
	printf("%d\n", ans);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

