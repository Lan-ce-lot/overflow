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
struct node {
	string c;
	int l, r;
}T[maxn];
int fa[maxn], root = 1;
void dfs(int u) {
	if (u == -1) return; 
	if (T[u].r != -1 && u != root) cout << '(';
	dfs(T[u].l);
	cout << T[u].c;
	dfs(T[u].r);
	if (T[u].r != -1 && u != root) cout << ')';
}
void solve()
{
	n = read();
	for (int i = 0; i < 10 * n; i++) {
		T[i].l = -1;
		T[i].r = -1;
	}
	memset(fa, 0, sizeof fa);
	for (int i = 1; i <= n; i++) {
		cin >> T[i].c >> T[i].l >> T[i].r;
		if (T[i].l != -1) fa[T[i].l] = i;
		if (T[i].r != -1) fa[T[i].r] = i;
	}
	while (fa[root]) root = fa[root];
	dfs(root);
	puts("");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

