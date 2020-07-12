#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k, ID, temp;
vector<int> G[105];
int ans[105];
int nl[105], maxdep = 0;
// 结点和非叶结点 

void dfs(int n, int dep) {
	
	
	if (G[n].size() == 0) {
		ans[dep]++;
		maxdep = max(maxdep, dep);
		return ;
	}
	
	for (int i = 0; i < G[n].size(); i++) {
		dfs(G[n][i], dep + 1);
	}
	
}


int main() {
	while (cin >> n >> m) {
		if (n == 0) return 0;
		int con = 0;
		maxdep = 0;
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < m; i++) {
			cin >> ID >> k;
			for (int j = 1; j <= k; j++) {
				
				cin >> temp;
				G[ID].push_back(temp);
				
			}
		}
		
		dfs(1, 0);
		
		for (int i = 0; i <= maxdep; i++) {
			if (i != 0) cout << ' ';
			cout << ans[i];
		}
		puts("");
	}
	
	
	
	return 0;
} 
