#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1000100 + 5;
int n, m, k;
vector<int> G[1000100];
int no[1000100], ans;
// cite way o
bool vis[1000100];
void dfs(int a) {
	if (vis[a]) {
		return;
	}
//	cout << "->" << a ;
	vis[a] = 1;
	for (int i = 0; i < G[a].size(); i++) {
		dfs(G[a][i]);
	}
}


int main () {
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 0; i < k; i++) {
		ans = 0;
		memset(vis, 0, sizeof vis);
		int b;
		scanf("%d", &b);
		vis[b] = 1;
		
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				dfs(j);
//				puts("");
				ans++;
			}
		}printf("%d\n", ans - 1);
	}
	
//	for (int i = 0; i < n; i++) {
//		printf("%d\n", ans[i] - 1);
//	}
	return 0;
}
