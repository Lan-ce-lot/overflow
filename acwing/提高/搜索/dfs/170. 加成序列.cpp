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
//bool vis[100];
int path[100];
bool dfs(int u, int dep) {
	if (u > dep) return 0;
	if (path[u - 1] == n) return 1;
//	if (u == dep) return path[u - 1] == n;
//	memset(vi)
	bool st[110] = {0};
	for (int i = u - 1; i >= 0; i--) 
		for (int j = i; j >= 0; j--) {
			int s = path[i] + path[j];
			if (s > n || s <= path[u - 1] || st[s]) continue;
			st[s] = 1;
			path[u] = s;
			if (dfs(u + 1, dep)) return 1;
		}
	return 0;
} 
void solve()
{
	path[0] = 1;
	while (cin >> n, n) {
		int de = 1;
		while (!dfs(1, de)) de++;
		for (int i = 0; i < de; i++) cout << path[i] << ' ';
		puts("");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
