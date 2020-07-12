#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

const int MAXN = 1e6 + 5;

using namespace std;
int n, m;
int par[MAXN];
int ste[MAXN];
int find(int x) {
	return x == par[x] ? x : x = find(par[x]);
}

void unite(int x, int y) {
	par[find(x)] = find(y);
}

int change(int x, int y) {
	return (x) * n + y;
}

int main() {
	
	for (int i = 0; i < MAXN; i++ ){
		par[i] = i;
	}
	
	cin >> n >> m;
	
	char c;
	int res = -1;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b >> c;
		a--, b--;
		a = change(a, b);
		if (c =='R') {
			if (find(a) == find(a + 1) ){
//				cout << i + 1 << endl;
				res = res == -1 ? i + 1 : res;
			} else {
				unite(a, a + 1);
			}
		} else if (c == 'D'){
			if (find(a) == find(a + n)) {
				res = res == -1 ? i + 1 : res;
			} else {
				unite(a, a + n);
			}
		} if (m - 1 == i) {
			if (res == -1) puts("draw");
			else cout << res << endl;
		}
	} 
	
	
	return 0;
}
 
