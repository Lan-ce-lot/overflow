#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;


vector<int> G[10005];
vector<int> room[105];

int n, m, ans = 0x3f3f3f3f;

void dfs(int st, int ro) {
	if (ro >= ans) return;
	if (st > n) {
		ans = min(ans, ro);
		return;
	}
	for (int i = 1; i <= ro; i++) {
		int flag = 0;
		for (int j = 0; j < room[i].size(); j++) {
			if (count(G[st].begin(), G[st].end(), room[i][j])) {
				flag = 1;break;
			} 
		}
		if (!flag) {
			room[i].push_back(st);
			dfs(st + 1, ro);
			room[i].pop_back();
		}
	}
	room[ro + 1].push_back(st);
	dfs(st + 1, ro + 1);
	room[ro + 1].pop_back();
}


int main() {
	map<int, int> M;
	M[0] = 1;
	cout << M.count(1);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, 0); //xs, room
	cout << ans << endl;
	return 0;
}

