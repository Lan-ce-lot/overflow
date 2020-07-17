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

int q[15], w[5][15];
int t, n;
int f() {
	int cnt = 0;
	for (int i = 0; i + 1 < n; i++) {
		if (q[i + 1] != q[i] + 1) cnt++;
	}
	return (cnt + 2) / 3;
}

bool check() {
	for (int i = 0; i + 1 < n; i++) 
		if (q[i + 1] != q[i] + 1) return false;
	return true;
}

bool dfs(int depth, int max_depth) {
	if (depth + f() > max_depth) return 0;
	if (check()) return 1;
	
	for (int len = 1; len <= n; len ++) {
		for (int l = 0; l + len - 1 < n; l++) {
			int r = l + len - 1;
			for (int k = r + 1; k < n; k++) {
				memcpy(w[depth], q, sizeof q);
				int x, y;
				for (x = r + 1, y = l; x <= k; x ++, y ++)
					q[y] = w[depth][x];
				for (x = l; x <= r; x++, y++) 
					q[y] = w[depth][x];
				if (dfs(depth + 1, max_depth)) return true;
				memcpy(q, w[depth], sizeof q);
			} 
		}
	}
	return 0;
}

void solve()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}
		int depth = 0;
		while (depth < 5 && !dfs(0, depth)) depth++;
		if (depth >= 5) puts("5 or more");
		else cout << depth << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

