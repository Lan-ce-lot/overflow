#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

struct node{
	int l ,r, e;
}tree[MAXN * 4];

int a[MAXN];
int n, m;
void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r) {
		tree[p].e = a[l];
		return ;
	} else {
		int mid = l + r >> 1;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
		tree[p].e = tree[p * 2].e + tree[p * 2 + 1].e;
		return ;
	}
} 

void update(int p, int i, int k) {
	if (tree[p].l == tree[p].r) {
		tree[p].e += k;
		return ;
	}
	int mid = tree[p].l + tree[p].r >> 1;
	if (i <= mid) update(p * 2, i, k);
	else update(p * 2 + 1, i, k);
	tree[p].e = tree[p * 2].e + tree[p * 2 + 1].e;
}

int query(int p, int x, int y) {
	if (x <= tree[p].l && y >= tree[p].r) return tree[p].e;			// 出口 
	int mid = tree[p].l + tree[p].r >> 1;
	if (y <= mid) return query(p * 2, x, y);						// 左 
	else if (x > mid) return query(p * 2 + 1, x, y);				// 右 			
	return query(p * 2, x, mid) + query(p * 2 + 1, mid + 1, y);		// 中间 
}


int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			update(1, y, z);
		} else {
			printf("%d\n", query(1, y, z));
		}
	}
	return 0;
}

