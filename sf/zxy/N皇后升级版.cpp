#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int f, a[maxn], vis[maxn], n;
bool check(int x, int j) {
	a[x] = j;
	for (int i = 1; i < x; i++)
		for (int j = i + 1; j <= x; j++)
			if (abs(a[i] - a[j]) == abs(i - j)) return 0;
	for (int i = 1; i <= x; i++) {
		for (int j = i + 1; j <= x; j++) {
			for (int k = j + 1; k <= x; k++) {
				if ((a[j] - a[i]) * (k - j) == (a[k] - a[j]) * (j - i)) return 0;
			}
		}
	}
	a[x] = 0;
	return 1;
}

void dfs(int u) {
	if (f) return ;
	if (u == n + 1) {
		f = 1;
		for (int i = 1; i <= n; i++) {
			if (i > 1) cout << ' ';
			cout << a[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && check(u, i)) {
			vis[i] = 1;
			a[u] = i;
			dfs(u + 1);
			a[u] = 0;
			vis[i] = 0;
		}
	}
}

int main() {
    while (cin >> n) {
		if (!n) break;
		f = 0;
		dfs(1);
		if (!f) puts("Impossible!!!");
	}
}
