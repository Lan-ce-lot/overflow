/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 + 5;

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
int t, n, m, a[maxn];

struct node {
	int l, r;
	ll sum, add;
}tr[maxn << 2]; 

void pushup(int p) {
	tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}

void pushdown(int p) {
	node &root = tr[p], &left = tr[p << 1], &right = tr[p << 1 | 1];
	if (root.add) {
		left.add += root.add, left.sum += (ll)(left.r - left.l + 1) * root.add;
		right.add += root.add, right.sum += (ll)(right.r - right.l + 1) * root.add;
		root.add = 0;
	}
}


void build(int p, int l, int r) {
	if (l == r) tr[p] = {l, r, a[r], 0};
	else {
		tr[p] = {l, r};
		int mid = tr[p].l + tr[p].r >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		pushup(p);
	}
}

void modify(int p, int l, int r, int d) {
	if (l <= tr[p].l && tr[p].r <= r) {
		tr[p].sum += (ll)(tr[p].r - tr[p].l + 1) * d;
		tr[p].add += d;
	} else { // ╥жая 
		pushdown(p);
		int mid = tr[p].l + tr[p].r >> 1;
		if (l <= mid) modify(p << 1, l, r, d); 
		if (r > mid)  modify(p << 1 | 1, l, r, d);
		pushup(p);
	}
}

ll query(int p, int l, int r) {
	if (l <= tr[p].l && tr[p].r <= r) return tr[p].sum;
	pushdown(p);
	int mid = tr[p].l + tr[p].r >> 1;
	if (r <= mid) return query(p << 1, l, r);
	if (l > mid)  return query(p << 1 | 1, l, r);
	return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
}

int main()
{
//    ios::sync_with_stdio(false);
	
	n = read();
	m = read();
	
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	build(1, 1, n);
	char c[5];
	int l, r, d;
	while (m--) {
		scanf("%s%d%d", c, &l, &r);
		if (*c == 'C') {
			scanf("%d", &d);
			modify(1, l, r, d);
		} else {
			printf("%lld\n", query(1, l, r));
		}
	}
	



    return 0;
}

