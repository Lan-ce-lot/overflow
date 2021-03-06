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
string s1, s2;
int tree[maxn];
int turn(string s) {
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			res *= 10;
			res += s[i] - '0';
		} else {
			return -1;
		}
	}
	return res;
}
struct node {
	int l, r;
}T[maxn];
int fa[maxn];

void build(int u, int v) {
	tree[u] = v;
	if (v == -1) return;
	build(u << 1, T[v].l);
	build(u << 1 | 1, T[v].r);
}
void solve()
{
	n = read();	
	memset(fa, -1, sizeof fa);
	memset(tree, -1, sizeof fa);
	for (int i = 0; i < n; i++) {
		cin >> s1  >> s2;
		T[i].l = turn(s1), T[i].r = turn(s2);
		fa[T[i].l] = fa[T[i].r] = i;
	}
	int root = 0;

	while (fa[root] != -1) {
		root = fa[root];
	}
	build(1, root);
	int con  = 0, ans = root;
	for (int i = 1; i <= n; i++) {
		if (tree[i] != -1) {
			con++;
		}
	}
	if (con == n) cout << "YES " << tree[n] << endl;
	else cout << "NO " << ans << endl;
}

int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

