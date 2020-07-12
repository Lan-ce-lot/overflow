#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 1e6;

int n, m;
int a[MAXN];
int e[MAXN];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i)) e[i] += k;
}

int sum(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += e[i];
	return res;
}
int a1, b1, c1;
char c[10];
int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		add(i, a[i] - a[i - 1]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", c);
		if (c[0] == 'Q') {
			scanf("%d", &a1);
			printf("%d\n", sum(a1));
		} else {
//			cout << 1 << endl;
			scanf("%d%d%d", &a1, &b1, &c1);
			add(a1, c1);
			add(b1 + 1, -c1);
		}
	}
	return 0;
} 
