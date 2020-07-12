#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int sum = 0, step;// sj
double ans;
int n, m;
bool st[105];
int G[105][105];

bool vis[105][105];
int in;
void dfs(int a, int s) {
	
	if (a == in && s) {
//		step = s;
		step++;
		sum += s;
//		puts("");
//		cout << "->"<< s;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (G[a][i] && vis[a][i] == 0 && st[i] == 0) {
			st[i] = 1;
			vis[i][a] = 1;
//			cout << "->" << i;
			dfs(i, s + 1);
			vis[i][a] = 0;
			st[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
//	in = 2;
//	dfs(2, 0);
	for (int i = 1; i <= n; i++) {
		sum = 0;
		step = 0;
		memset(vis, 0, sizeof vis);
		
		in = i;
		dfs(i, 0);
		printf("%.12f\n", sum * 1.0 / step * 1.0);
		
	}
	
	return 0;
} 
