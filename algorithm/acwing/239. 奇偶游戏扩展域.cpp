#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>

using namespace std;
const int MAXN = 1e5 + 5;
struct node{
	int l, r;
	int f;
}N[MAXN];
int temp[MAXN * 2], cnt = 0;
int n, m, a, b;
char c[10];
int p[MAXN * 2], d[MAXN];

int find(int x) {
	if (x != p[x]) {
		int root = find(p[x]);
		d[x] = d[x] ^ d[p[x]];
		p[x] = root;
	}
	return p[x];
}

void unite(int x, int y) {
	p[find(x)] = find(y);
}

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%s", &N[i].l, &N[i].r, c);
		temp[cnt++] = N[i].l - 1;
		temp[cnt++] = N[i].r;
		N[i].f = c[0] == 'o' ? 1 : 0;
	}
	sort(temp, temp + cnt);
	int all_n = unique(temp, temp + cnt) - temp;
//	for (int i = 0; i < all_n; i++) cout << temp[i] <<' ';
	for (int i = 0; i <= all_n * 2; i++) p[i] = i;
	
	for (int i = 0; i < m; i++) {
		int x = lower_bound(temp, temp + all_n, N[i].l - 1) - temp + 1;
		int y = lower_bound(temp, temp + all_n, N[i].r) - temp + 1;

		
		if (N[i].f) {
			if (find(x) == find(y)) {
				printf("%d\n", i);
				return 0;
			} else {
				unite(x, y + all_n);
				unite(x + all_n, y);
			}
		} else {
			if (find(x) == find(y + all_n)) {
				printf("%d\n", i);
				return 0;
			} else {
				unite(x, y);
				unite(x + all_n, y + all_n);
			}
		}
		
	}
	
	printf("%d\n", m);
	return 0;
}
