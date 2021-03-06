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
int t, n, f[maxn][2];
int h[maxn], e[maxn], ne[maxn], tot;
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}

void dfs(int u, int fa) {
	
	f[u][0] = 0;
	f[u][1] = 1;
	for (int i = h[u]; ~i; i = ne[i]) {
		int to = e[i];
		if (to != fa) {
			dfs(to, u);
			f[u][0] += f[to][1];
			f[u][1] += min(f[to][1], f[to][0]);
		}
	}
}

void solve()
{
	memset(h, -1, sizeof h);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b;
		while (b--) {
			cin >> c;
			add(a, c);
			add(c, a);
		}
	}
	dfs(1, -1);
	cout << min(f[1][0], f[1][1]) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

