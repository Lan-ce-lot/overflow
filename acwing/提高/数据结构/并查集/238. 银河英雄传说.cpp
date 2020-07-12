#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

const int MAXN = 1e6 + 5;

using namespace std;
int t, a, b;
char c[3];

int par[MAXN], s[MAXN], d[MAXN];
// s->size, d->distant
int find(int x) {
	if (x != par[x]) {
		int root = find(par[x]);
		d[x] += d[par[x]];
		par[x] = root;
	} 
	return par[x];
}




int main() {
	cin >> t;
	for (int i = 0; i < MAXN; i++) {
		par[i] = i;
		s[i] = 1;
	}
	while (t--) {
		scanf("%s%d%d", c, &a, &b);
		if (c[0] == 'M') {
			int pa = find(a), pb = find(b);
			d[pa] = s[pb];
			s[pb] += s[pa];
			par[pa] = pb; 
			
		} else {
			int pa = find(a), pb = find(b);
			if (pa != pb) puts("-1");
			else printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
			
		}
		
	}
	
	return 0;
}
