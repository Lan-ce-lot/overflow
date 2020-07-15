#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;
int m, p;
struct node{
	int l, r;
	ll sum, add;
}tr[MAXN * 4];
ll a[MAXN];
void pushup(int p) {
	tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}

void pushdown(int p) {
	node &root = tr[p], &left = tr[p << 1], &right = tr[p << 1 | 1];
	if (root.add) {
		left.sum += (ll)(left.r - left.l + 1) * (root.add), left.add += root.add;
		right.sum += (ll)(right.r - right.l + 1) * (root.add), right.add += root.add;
		root.add = 0;
	}
}

void build(int p, int l, int r) {
	tr[p] = {l, r};
	if (l == r) {
		tr[p] = {l, r, a[l], 0};
		return ;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void modify(int p, int l, int r, int k) {
	if (l <= tr[p].l && tr[p].r <= r) {
		tr[p].sum += (ll)(tr[p].r - tr[p].l + 1) * k;
		tr[p].add += k;
		return ;
	}
	pushdown(p);
	int mid = tr[p].l + tr[p].r >> 1;
	if (l <= mid) modify(p << 1, l, r, k);
	if (r >  mid) modify(p << 1 | 1, l, r, k);
	pushup(p);
}

ll query(int p, int l, int r) {
	if (l <= tr[p].l && tr[p].r <= r) {
		return tr[p].sum;
	}
	
	pushdown(p);
	int mid = tr[p].l + tr[p].r >> 1;
	if (r <= mid) return query(p << 1, l, r);
	if (l >  mid) return query(p << 1 | 1, l, r);
	return query(p << 1 ,l, r) + query(p << 1 | 1, l, r);

}
//ll query(int p, int l, int r) {
//	if (l <= tr[p].l && tr[p].r <= r) return tr[p].sum;
//	pushdown(p);
//	int mid = tr[p].l + tr[p].r >> 1;
//	ll res = 0;
//	if (l <= mid) res += query(p << 1, l, r);
//	if (r >  mid) res += query(p << 1 | 1, l, r);
//	return res;
//}


int main() {
	ll n = 0, last = 0, l, r;
	scanf("%d%d", &m, &p);
	for (int i = 1; i <= m; i++) scanf("%lld", &a[i]);
	build(1, 1, m);
//	cout << 1 << endl;
	int x;
	char op[2];
	while (p--) {
		scanf("%s%d%d", op, &l, &r);
		if (*op == 'Q') {
			last = query(1, l, r);
//			last = query(1, n - x + 1, n);
			printf("%lld\n", last);
		} else {
			int k;
			scanf("%d", &k);
			modify(1, l, r, k);
//			modify(1, n + 1, (last + x) % p);
			n++;
		}
	}
	return 0;
}
