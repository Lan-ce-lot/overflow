#include <bits/stdc++.h>

using namespace std;
int n, v;
int V[100005], W[1000005], f[100005];
int main() {
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> V[i] >> W[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = V[i]; j <= v; j++) {
			f[j] = max(f[j], f[j - V[i]] + W[i]);
		}
	}
	cout << f[v] << endl;
	return 0;
}

