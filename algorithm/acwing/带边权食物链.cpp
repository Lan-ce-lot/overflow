#include<iostream>
#include<cstring>
#include<cstdio>
#include<unordered_map>

using namespace std;

const int MAXN = 1e6 + 5;

int n, m;

int p[MAXN], ans;
int d[MAXN];

int find(int x) {
	if (p[x] != x) {
		int root = find(p[x]);
		d[x] += d[p[x]];
		p[x] = root;
	}
	return p[x];
}

int main() {
	
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
	
	while (m--) {
		int f, a, b;
		
		
		
		scanf("%d%d%d", &f, &a, &b);
		if (a > n || b > n) {
			ans++;
			continue;
		}
		int pa = find(a), pb = find(b);
		if (f == 1) {
			if (pa == pb && ((d[a] - d[b]) % 3 + 3) % 3) {
				ans ++;
			} else if (pa != pb){
				p[pa] = pb;
				d[pa] = ((d[b] - d[a]) % 3 + 3) % 3;
			}	
		} else {
			if (pa == pb && ((d[a] + 1 - d[b]) % 3 + 3) % 3) {
				ans++;
			} else if (pa != pb) {
				p[pa] = pb;
				d[pa] = ((d[b] - d[a] - 1) % 3 + 3) % 3;
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
