#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, m, t, a, b, k, now;
string s[1005];
vector<int> G[10005];
stack<char> S; 
struct node {
	int x, y;
	vector<int> V;
};
const int INF = 0x3f3f3f3f;
int h[maxn], tot, e[maxn], ne[maxn];
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot++;
}

int maxx = -INF;

vector<int> tmp, ans;
void dfs(int u) {
	if (G[u].size() == 0) {
		if (maxx < int(tmp.size())) {
			maxx = tmp.size();
			ans = tmp;
		}
		return;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		tmp.push_back(to);
		dfs(to);
		tmp.pop_back();
	}
}

int main() {
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 0; i < n; i++) {
		cin >> k;
		while (k--) {
			cin >> a;
			G[i].push_back(a);
		}
		sort(G[i].begin(), G[i].end());
	}
	dfs(0);
	cout << ans.size() + 1 << endl;
	cout << 0;
	for (int i = 0; i < ans.size(); i++) {
		cout << ' ' << ans[i] ;
	}
	cout << endl;
}
