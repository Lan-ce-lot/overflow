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
	int l, r;
}T[maxn];
char a, b;
int a_i, b_i;
int fa[maxn];
int tree[maxn];
int con = 0;
void in(int u) {
	if (u == -1) return;
	in(T[u].l);
	con++; 
	printf("%d", u);
	if (con >= n) cout << endl;
	else cout << ' ';
	in(T[u].r);
}
void build(int u, int v) {
	if (v == -1) 
		return;
	tree[u] = v;
	build(u << 1, T[v].l);
	build(u << 1 | 1, T[v].r);
}
void solve()
{
	n = read();
	memset(fa, -1, sizeof fa);
	memset(tree, -1, sizeof tree);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a >= '0' && a <= '9') {
			a_i = a - '0';
			fa[a_i] = i;
		} else {
			a_i = -1;
		}
		if (b >= '0' && b <= '9') {
			b_i = b - '0';
			fa[b_i] = i;
		} else {
			b_i = -1;
		}
		T[i].l = b_i, T[i].r = a_i;
	}
	int root = 0;
	while (fa[root] != -1) {
		root = fa[root];
	}	
	build(1, root);
	int cc = 0;
	for (int i = 1;; i++) {
		if (tree[i] == -1) continue;
		cout << tree[i];
		cc++;
		if (cc == n) {
			cout << endl;
			break;
		}
		else cout << ' ';
	}

	in(root);

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

