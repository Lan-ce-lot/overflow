#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, m, t, a, b, k, now;
ll all[10005][105];
vector<int> G[maxn];
int M[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		while (k--) {
			cin >> a;
			G[i].push_back(a);
		}
	}
	int now = 1; 
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a == 1) {
			M[b] = now;
			cout << now << endl;
		} else if (a == 0) {
			now = G[now][b - 1];
		} else if (a == 2) {
			now = M[b];
		}
	}
	cout << now << endl;
}
