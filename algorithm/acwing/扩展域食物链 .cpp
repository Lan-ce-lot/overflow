#include<iostream>
#include<cstring>
#include<cstdio>
#include<unordered_map>

using namespace std;

const int MAXN = 1e6 + 5;

int n, m;

int p[MAXN * 3], ans;
int d[MAXN];

int find(int x) {
	if (p[x] != x) {
		p[x] = find(p[x]); 
	}
	return p[x];
}

void unite(int a, int b) {
	p[find(a)] = find(b);
	
}

int main() {
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i <= n * 3; i++) {
		p[i] = i;
	}
	
	while (m--) {
		int f, a, b;
	
		scanf("%d%d%d", &f, &a, &b);
		if (a > n || b > n) {
			ans++;
			continue;
		}
//		int pa = find(a), pb = find(b);
		if (f == 1) {
			if (find(a) == find(b + n) || find(a) == find(b + 2 * n)) {
				ans++;
			} else {
				unite(a, b);
				unite(a + n, b + n);
				unite(a + 2 * n, b + 2 * n);
			}
		} else {
			if (find(a) == find(b) || find(a) == find(b + 2 * n)) {
				ans++;
			} else {
				unite(a, b + n);
				unite(a + n, b + 2 * n);
				unite(a + 2 * n, b);
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
