#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN = 2e5 + 5;
int m, p;
struct node{
	int l, r;
	int ma;
}tr[MAXN * 4];

void pushup(int u) {
	tr[u].ma = max(tr[u << 1].ma, tr[u << 1 | 1].ma);
}

void build(int u, int l, int r) {
	tr[u] = {l, r};
	if (l == r) return ;
	
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].ma;
	int mid = tr[u].l + tr[u].r >> 1;
	int v = 0;
	if (l <= mid) v = max(v, query(u << 1, l, r)); 
	if (r > mid) v = max(v, query(u << 1 | 1, l, r));
	return v;
	
}

void modify(int u, int x, int k) {
	if (tr[u].l == tr[u].r) {tr[u].ma = k;return ;}
	int mid = tr[u].l + tr[u].r >> 1;
	if (x <= mid) modify(u << 1, x, k);
	else modify(u << 1 | 1, x, k);
	pushup(u);
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
