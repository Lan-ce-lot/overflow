#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;
int m, mod, n, q;
struct node{
	int l, r;
	ll sum, add, mul;
}tr[MAXN * 4];

ll a[MAXN];

void pushup(int p) {
	tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum) % mod;
}

void eval(node &p, ll a, ll m) {
	p.sum = (p.sum * m + (p.r - p.l + 1) * a) % mod;
	p.mul = p.mul * m % mod;
	p.add = (p.add * m + a) % mod;
}

void pushdown(int p) {
	eval(tr[p << 1], tr[p].add, tr[p].mul);
	eval(tr[p << 1 | 1], tr[p].add, tr[p].mul);
	tr[p].add = 0, tr[p].mul = 1;
}

void build(int p, int l, int r) {
	tr[p] = {l, r, 0, 0, 1};
	if (l == r) {
		tr[p] = {l, r, a[l], 0, 1};return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, ll a, ll m) {
	if (l <= tr[p].l && tr[p].r <= r) {
		eval(tr[p], a, m);
		return;
	}
	pushdown(p);
	int mid = tr[p].l + tr[p].r >> 1;
	if (l <= mid) modify(p << 1, l, r, a, m);
	if (r >  mid) modify(p << 1 | 1, l, r, a, m);
	pushup(p);
}

ll query(int p, int l, int r) {
	ll res = 0;
	if (l <= tr[p].l && tr[p].r <= r) {
		return tr[p].sum;
	}	
	pushdown(p);
	int mid = tr[p].l + tr[p].r >> 1;
	if (l <= mid) res = (res + query(p << 1, l, r)) % mod;
	if (r >  mid) res = (res + query(p << 1 | 1, l, r)) % mod;
	return res;
}


int main() {
	int n = 0, last = 0;
	scanf("%d%d", &n, &mod);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	
	scanf("%d", &m);
	while (m--) {
		int t, l, r, d;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			scanf("%d", &d);
			modify(1, l, r, 0, d);
		} else if (t == 2) {
			scanf("%d", &d);
			modify(1, l, r, d, 1);
		} else {
			printf("%d\n", query(1, l, r));
		}
	}
	return 0;
}
