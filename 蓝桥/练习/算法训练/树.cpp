#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

const int MAXN = 1e6 + 5;
int n, m;
int e[MAXN * 4];
int a[MAXN];

int lowbit(int x) {
	return x & -x;
}

void update(int i, int k) {
	while (i <= n) {
		e[i] += k;
		i += lowbit(i);
	}
}

int query(int i) {
	int res = 0;
	while (i > 0) {
		res += e[i];
		i -= lowbit(i);
	}
	return res;
}

void init() {
	for (int i = 1; i <= n; i++) {
		update(i, a[i]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	init();
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) {
			update(y, z);
		} else {
			printf("%d\n", query(z) - query(y - 1));
		}
	}
	
	
	return 0;
}

