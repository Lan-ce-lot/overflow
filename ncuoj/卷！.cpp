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
int t, n, m;
int know[maxn];
int h[maxn], ne[maxn], tot = 1, e[maxn];

void add(int a, int b) {
	e[tot] = b, ne[tot] =h[a] , h[a] = tot++;
}

bool is_leaf[maxn];
//void dfs(int now, int fa) {
//	if () {
//		
//	}
//	
//	for (int i = h[now]; i; i = ne[i]) {
//		int to = e[i];
//		if (to == fa) continue;
//		dfs();
//	}
//}
vector<int> G[100005];

void dfs(int now, int fa) {
	
	for (int i = 0; i < G[fa].size(); i++) {
		int to = G[fa][i];
		if (to == fa) continue;
		dfs(to, now);
		is_leaf[now] = 1;
	}
}

void solve()
{
	
	n = read(), m = read();
	for (int i = 0; i < n - 1; i++) {
		int a = read(), b = read();
		G[a].push_back(b);
		G[b].push_back(a);
//		add(read(), read()); 
	}
	dfs(1, 0);
//	for (int i = 1; i <= n; i++) {
//		if (G[i].size() <= 1) is_leaf[i] = 1;
//	}
	for (int i = 0; i < m; i++) {
		know[i] = read();
		is_leaf[know[i]] = 1;
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		if (is_leaf[i] == 0) {
			flag = 1;
			break;
		}
	}
	printf("%s\n", flag?"NO":"YES");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

