#include<bits/stdc++.h>
#define ls (k << 1)
#define rs (ls | 1)
using namespace std;
typedef long long ll;
const int N = 2e3 + 5, M = 2e6 + 5;
int T, n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char s[N][N];
int num = 0;
int dfs(int x, int y) {
	int sum = 0;
	s[x][y] = '*';
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
			continue;
		if (s[nx][ny] == '.')	sum++;
		if (s[nx][ny] != '@')	continue;
		sum += dfs(nx, ny);
	}
	return sum;
}
int main(){
	scanf("%d", &T);
	while (T--) {
		num = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) 
			scanf("%s", s[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] != '*')	continue;
				for (int k = 0; k < 4; k++) {
					int nx = dx[k] + i, ny = dy[k] + j;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
						continue;
					if (s[nx][ny] == '.') {
						s[nx][ny] = '@';
						num++;	
					}
				}
			}
		}
		if (!num) {
			printf("NO\n");
			continue;
		}
		num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '@') {
					if (!dfs(i, j))
						num++;
				}
			}
		}
		if (num <= 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
