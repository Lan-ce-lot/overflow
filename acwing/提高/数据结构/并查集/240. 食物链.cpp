#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

const int MAXN = 1e6 + 5;

using namespace std;
int t, a, b, n, k;
int c;

int par[MAXN * 3], s[MAXN], d[MAXN];

int find(int x) {
	if (x != par[x]) {
		int root = find(par[x]);
		
		d[x] += d[par[x]];
		par[x] = root;
//		return root;
//		par[x] = root;
	} 
	return par[x];
}




int main() {

	
	cin >> n >> k;
	for (int i = 0; i < MAXN; i++) {
		par[i] = i;
		s[i] = 1;
	}
	
	int ans = 0;
	while (k--) {
		scanf("%d%d%d", &a, &b, &c);
		if (b > n || c > n) {
			ans++;
			continue;
		}
		int pa = find(b), pb = find(c);
		if (a == 1) {
			
			if (pa == pb && (d[b] - d[c]) % 3) {
				ans++;
			} else if (pa != pb) {
				par[pa] = pb;
				d[pa] = d[c] - d[b];
			}
		} else {
			if (pa == pb && (d[b] - d[c] - 1) % 3) {
				ans++;
			} else if (pa != pb) {
				par[pa] = pb;
				d[pa] = d[c] + 1 - d[b];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
