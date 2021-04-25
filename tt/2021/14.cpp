#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
ll n, m, t, a, b, k, now, u, v, c,d;
ll all[maxn];
int h[maxn], tot;

vector<int> G[maxn];

int cit[maxn];
vector<int> ans, tmpp;
bool vis[maxn];
int ff = 0;
void dfs(int u, int pp) {
	if (ff ==  1) return ;
	int tmp = pp;
	// 3 6 1 5 2 4
	if (pp >= n - 1) {
		ans = tmpp;
		return;
	}
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (to != all[tmp]) {
			return ;
		}
		tmp++;
	}
	if (tmp >= n) {
		ff = 1;
		tmpp.push_back(u);
		ans = tmpp;
		return ;
	}
	tmpp.push_back(u);vis[u] = 1;
	for (int j = 1; j <= m; j++) {
		if (vis[j] == 0) {
			dfs(j, tmp - 1);
		}
	}tmpp.pop_back();vis[u] = 0;

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> all[i];
	} 
	cin >> m;
	for (int i = 1; i <= m ; i++) {
		cin >> k;
		while (k--) {
			cin >> a;
			G[i].push_back(a);
		}
	}
	for (int i = 1; i <= m; i++) {
//		tmpp.push_back(i);
tmpp.clear();
		dfs(i, 1);
//		tmpp.pop_back();
		if (ans.size() == m) break;
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout << ' ' << ans[i];
	}puts("");
	
}
