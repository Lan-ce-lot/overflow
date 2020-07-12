#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t;const int N = 2e6 + 5;
vector<int> G[N];
bool vis[N];
int ans = 0;

void dfs(int a) {
	if (vis[a]) return;
	vis[a] = 1;
	for (int i = 0; i < G[a].size(); i++) 
		dfs(G[a][i]);
}

int main () { 
	cin >> n >> m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= m * n; i++) 
		if (!vis[i]) {dfs(i);ans++;}
	cout << ans << endl;
	return 0;
}

