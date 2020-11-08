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
int a[maxn << 2];
struct node{
	int l, r;
	PII v;
}N[maxn];
void dfs(int u, int l, int r) {
	N[u].l = l, N[u].r = r;
	if (l == r) {
		N[u].v = {a[l], l};return;
	}
	int mid = l + r >> 1;
	dfs(u << 1, l, mid);
	dfs(u << 1 | 1, mid + 1, r);
	N[u].v = max(N[u << 1].v, N[u << 1 | 1].v);
}

void solve()
{
	ll all = read();
	n = (1 << all);
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	dfs(1, 1, n);
	PII ans;
	if (N[2].v.first < N[3].v.first) {
		cout << N[2].v.second << endl;
	} else {
		cout << N[3].v.second << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

