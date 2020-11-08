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
#define x first
#define y second
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
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
int t, n, m, ans = 0;
vector<PII> G[maxn];

int dfs(int u, int f) {
	int dis = 0;// 当前最长距离 
	int d1 = 0, d2 = 0;
	
	for (int i = 0; i < G[u].size(); i++) {
		auto tem = G[u][i];
		if (tem.x == f) continue;
		
		int d = dfs(tem.x, u) + tem.y;
		dis = max(d, dis);
		if (d >= d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
	}
	ans = max(ans, d1 + d2);
	return dis;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a = read(), b = read(), c = read();
		G[a].push_back({b, c});
		G[b].push_back({a, c});
		
	} 
	dfs(1, -1);
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

