#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

const int MAXN = 1e5 + 5;
int p[MAXN];
int d[MAXN];

int n, m;
int a, b;
char c[10];
struct node{
	int l, r, f;
}N[MAXN];
int tem[MAXN * 2],cnt = 0; 

int find(int x) {
	if (p[x] != x) {
		int root = find(p[x]);
		d[x] ^= d[p[x]];
		p[x] = root;
	} 
	return p[x];
}

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%s", &a, &b, c);
		
		if (c[0] == 'o') {
			N[i] = {a - 1, b, 1};
		} else {
			N[i] = {a - 1, b, 0};
		}
		tem[cnt++] = a - 1;
		tem[cnt++] = b;
	}
	
	// 
	sort(tem, tem + cnt);
	int n = unique(tem, tem + cnt) - tem;
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		
		int l = lower_bound(tem, tem + n, N[i].l) - tem + 1;
		int r = lower_bound(tem, tem + n, N[i].r) - tem + 1;
		int pa = find(l);
		int pb = find(r);
		if (pa == pb) {
			if (d[l] ^ d[r] == N[i].f) {
				continue;
			} else {
				printf("%d\n", i);
				return 0;
			}
		} else {
			p[pa] = pb;
			d[pa] = d[l] ^ d[r] ^ N[i].f;
		}
	}
	printf("%d\n", m);
	return 0;
}
