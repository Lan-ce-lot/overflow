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
const int maxn = 15;
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
ll t, n, ans = 0;
bool vis[maxn], backup[maxn];

bool check(int a, int c) {
	ll b = n * c - c * a;
	
	if (a == 0 || b == 0 || c == 0) return 0;
	
	memcpy(backup, vis, sizeof vis);
	
	
	while (b) {
		int tem = b % 10;
		b /= 10;
		if (tem == 0 || backup[tem]) {
			return 0;
		} else {
			backup[tem] = 1;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (backup[i] == 0) {
			return 0;
		}
	}
	return 1;
}


void dfs_c(int u, int a, int c) {
	if (u > 9) {
		return;
	}
	if (check(a, c)) {
		ans++;
	}
	for (int i = 1; i <= 9; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs_c(u + 1, a, c * 10 + i);
			vis[i] = 0;
		}
	}
}

void dfs_a(int u, int a) {
	
	if (a >= n) {
		return;
	}
	if (a) dfs_c(u, a, 0);
	
	for (int i = 1; i <= 9; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs_a(u + 1, a * 10 + i);
			vis[i] = 0;
		}
	}
	
}



void solve()
{
	n = read();
	dfs_a(0, 0);
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

