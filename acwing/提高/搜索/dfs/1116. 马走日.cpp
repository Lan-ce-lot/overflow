#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 15;

int t, n, m, s_n, s_m;


int dir[8][2] = {2, 1, 1, 2, -1, 2, -2, 1, -2, -1, -1, -2, 1, -2, 2, -1};
bool vis[maxn][maxn];

int ans = 0;

bool test(int x, int y) {
	return x >=0 && y >= 0 && x < n && y < m && (!vis[x][y]); 
}

void dfs(int x, int y, int step) {
	
	if (step == m * n) {
		ans++;
		return ;
	}
	vis[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		if (!test(x + dir[i][0], y + dir[i][1])) continue;
		dfs(x + dir[i][0], y + dir[i][1], step + 1);
	}
	vis[x][y] = 0;
}

int main() {
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		ans = 0;
		cin >> n >> m >> s_n >> s_m;
		dfs(s_n, s_m, 1);
		cout << ans << endl;
	}
}
