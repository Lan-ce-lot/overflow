#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN = 2e6 + 5;
int m, p;
struct node{
	int l, r;
	ll sum, tmax, lmax, rmax;
}tr[MAXN * 4];
ll a[MAXN];

void pushup(node &root, node &left, node &right) {
	root.sum = left.sum + right.sum;
	root.lmax = max(left.lmax, left.sum + right.lmax);
	root.rmax = max(right.rmax, right.sum + left.rmax);
	root.tmax = max(max(left.tmax, right.tmax), left.rmax + right.lmax);
}

void pushup(int p) {
	pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}

void build(int p, int l, int r) {
	tr[p] = {l, r};
	if (tr[p].l == tr[p].r) {
		tr[p] = {l, r, a[l], a[l], a[l], a[l]};
		return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void modify(int p, int x, int k) {
//	if (tr[p].l == tr[p].r) {
	if (tr[p].l == x && tr[p].r == x) {
		tr[p] = {x, x, k, k, k, k};
		return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	if (x <= mid)
		modify(p << 1, x, k);
	if (x > mid) 
		modify(p << 1 | 1, x, k);
	pushup(p);
}

node query(int p, int l, int r) {
	if (l <= tr[p].l &&  tr[p].r <= r) return tr[p];
	int mid = tr[p].l + tr[p].r >> 1;
	
	if (r <= mid) return query(p << 1, l, r);
	if (l > mid ) return query(p << 1 | 1, l, r);
	else {
		node res;
		node left = query(p << 1, l, r);
		node right = query(p << 1 | 1, l, r);
		pushup(res, left, right);
		return res;
	}
}

int main() {
	int n = 0, last = 0;
	scanf("%d%d", &m, &p);
	for (int i = 1; i <= m; i++) scanf("%lld", &a[i]);
	build(1, 1, m);
//	for (int i = 1; i <= m * 4; i++) cout << tr[i].sum << ' '; 
	while (p--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			if (l > r) swap(l, r);
			printf("%lld\n", query(1, l, r).tmax);
		} else {
			modify(1, l, r);
		}
	}

	return 0;
}
