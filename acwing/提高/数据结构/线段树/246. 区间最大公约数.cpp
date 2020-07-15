#include<iostream>
#include<cstdio>
#include<cstring>
<<<<<<< HEAD
typedef long long ll;
using namespace std;
const int MAXN = 500010;
int m, p;
struct node{
	int l, r;
	ll d, sum;
}tr[MAXN * 4];

ll a[MAXN];
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

void pushup(node &p, node &l, node &r) {
	p.sum = l.sum + r.sum;
	p.d = gcd(l.d, r.d);
}

void pushup(int p) {
	pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}

void build(int p, int l, int r) {
	tr[p] = {l, r};
	if (l == r) {
		ll b = a[r] - a[r - 1];
		tr[p] = {l, r, b, b};
		return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void modify(int p, int x, ll v) {
	if (tr[p].l == x && tr[p].r == x) {
		ll b = tr[p].sum + v;
		tr[p] = {x, x, b, b};
		return ;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	if (x <= mid) modify(p << 1, x, v);
	else modify(p << 1 | 1, x, v);
	pushup(p);
}

node query(int p, int l, int r) {
	if (tr[p].l >= l && tr[p].r <= r) return tr[p];
	int mid = tr[p].l + tr[p].r >> 1;
	if (r <= mid) return query(p << 1, l, r);
	if (l >  mid) return query(p << 1 | 1, l, r);
	else {
		node left = query(p << 1, l, r);
		node right = query(p << 1 | 1, l, r);
		node res;
		pushup(res, left, right);
		return res;
	}
=======

using namespace std;
const int MAXN = 2e5 + 5;
int m, p;
struct node{
	int l, r;
	int gcd, sum;
}tr[MAXN * 4];

void pushup(int p) {
	tr[p].sum = tr[p << 1].sum + 
>>>>>>> 188a392e84c960f37ec62f7a560710a7c57636e3
}


int main() {
<<<<<<< HEAD
	ll n = 0, last = 0;
	ll l, r, k;
	scanf("%d%d", &m, &p);
	for (int i = 1; i <= m; i++) scanf("%lld", &a[i]);
=======
	int n = 0, last = 0, l, r, k;
	scanf("%d%d", &m, &p);
>>>>>>> 188a392e84c960f37ec62f7a560710a7c57636e3
	build(1, 1, m);
	
	int x;
	char op[2];
	while (p--) {
<<<<<<< HEAD
		scanf("%s%lld%lld", op, &l, &r);
		if (*op == 'Q') {
			node left = query(1, 1, l);
			node right = query(1, l + 1, r);
			printf("%lld\n", abs(gcd(left.sum, right.d)));
		} else {
			scanf("%lld", &k);
			modify(1, l, k);
			if (r + 1 <= m) modify(1, r + 1, -k);
=======
		scanf("%s%d", op, &l, &r);
		if (*op == 'Q') {
			last = query(1, l, r);
			printf("%d\n", last);
		} else {
			scanf("%d", &k)
			modify(1, l, r, k);
//			n++;
>>>>>>> 188a392e84c960f37ec62f7a560710a7c57636e3
		}
	}
	return 0;
}
