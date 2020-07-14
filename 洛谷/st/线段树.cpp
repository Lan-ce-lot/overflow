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
int a[maxn];
struct node{
	int l, r, MAX;
}tr[maxn];

void pushup(int p) {
	tr[p].MAX = max(tr[p << 1].MAX, tr[p << 1 | 1].MAX);
}

void build(int p, int l, int r) {
	tr[p].l = l, tr[p].r = r;
	if (l == r) {
		// tr[p].MAX = a[l];
		return ;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	// pushup(p);
}

int query(int p, int l, int r) {
	if (l <= tr[p].l && tr[p].r <= r) {
		return tr[p].MAX;
	}
	int Max = -INF;
	int mid = tr[p].l + tr[p].r >> 1;
	if (l <= mid) {
		Max = max(Max, query(p << 1, l, r));
	}
	if (r > mid) {
		Max = max(Max, query(p << 1 | 1, l, r));
	}
	return Max;
}

void motify(int p, int l, int k) {
	tr[p].MAX = max(k, tr[p].MAX);
	if (tr[p].l == tr[p].r) {
		// tr[p].MAX = k;
		return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	if (l <= mid) {
		motify(p << 1, l, k);
	} else {
		motify(p << 1 | 1, l, k);
	}
	// pushup(p);
}

void solve() {
	n = read(), m = read();
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		motify(1, i, a[i]);
	}
	
	while (m--) {

		int l, r;
		l = read(), r = read();
		printf("%d\n",query(1,l,r));
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

