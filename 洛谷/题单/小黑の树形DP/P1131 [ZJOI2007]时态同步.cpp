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
int t, n;
ll h[maxn],  ne[maxn], tot = 1, ans = 0;
struct node {
	int to, cost;
}e[maxn];
void add(int a, int b, int c) {
	e[tot] = {b, c}, ne[tot] = h[a], h[a] = tot++;
}
ll dis[maxn];
void dfs(int u, int fa) {
	
	for (int i = h[u]; i; i = ne[i]) {
		int to = e[i].to, v = e[i].cost;
		if (fa == to) continue;
		
		
		dfs(to, u);
		
		dis[u] = max(dis[u], dis[to] + v);
		
	}
	
	
	for (int i = h[u]; i; i = ne[i]) {
		int to = e[i].to, v = e[i].cost;if(to==fa) continue;
		ans += dis[u] - (dis[to] + v);
		
	}
}

void solve()
{
	n = read();
	tot = 1;
	memset(h, 0, sizeof h);
	int root = read();
	for (int i = 1; i < n; i++) {
		int a = read(), b = read(), c = read();
		add(a, b, c);
		add(b, a, c);
	}
	dfs(root, 0);
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

