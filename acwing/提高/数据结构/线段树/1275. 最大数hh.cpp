#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
const int maxn = 2e5 + 5;
ll a[maxn];
struct node {
	int l, r;
	ll MAX;
}tr[maxn << 2];
int n, m, p;
void pushup(int p) {
	tr[p].MAX = max(tr[p << 1].MAX, tr[p << 1 | 1].MAX);
}

void build(int p, int l, int r) {
	tr[p] = {l, r};
	if (l == r) {
//		tr[p].MAX = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
//	pushup(p);
}

void modify(int p, int x, int k) {
	if (tr[p].l == tr[p].r) {
		tr[p].MAX = k;
		return ;
	}
	
	int mid = tr[p].l + tr[p].r >> 1;
	
	if (x <= mid) {
		modify(p << 1, x, k);
	}
	if (x > mid) {
		modify(p << 1 | 1, x, k);
	}
	pushup(p);
}

ll query(int p, int l, int r) {
	if (l <= tr[p].l && tr[p].r <= r) {
		return tr[p].MAX ;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	if (r <= mid) return query(p << 1, l, r);
	if (l > mid) return query(p << 1 | 1, l, r);
	return max(query(p << 1, l,  mid), query(p << 1 | 1, mid + 1, r));
}


int main() {
	int n = 0, last = 0;
	scanf("%d%d", &m, &p);
	build(1, 1, m);
	
	int x;
	char op[2];
	while (m--) {
		scanf("%s%d", op, &x);
		if (*op == 'Q') {
			last = query(1, n - x + 1, n);
			printf("%d\n", last);
		} else {
			modify(1, n + 1, (last + x) % p);
			n++;
		}
	}
	return 0;
}
