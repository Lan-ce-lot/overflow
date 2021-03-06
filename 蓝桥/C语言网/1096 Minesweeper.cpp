#include <iostream>
#include <cstring>

using namespace std;

char maze[1005][1005];
int n, m;
char ans[1005][1005];

char check(int x, int y) {
	if (maze[x][y] == '*') {
		return '*';
	}
	int res = 0;
	for (int i = max(0, x - 1); i <= min(n - 1, x + 1); i++) {
		for (int j = max(0, y - 1); j <= min(m - 1, y + 1); j++) {
			if (maze[i][j] == '*')
				res++;
		}
	}
	return char(res + '0');
}

int main () {
	
	int con = 0;
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", maze[i]);
		}
		printf("Field #%d:\n", ++con);
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[i][j] = check(i, j);
			}
		}
		for (int i = 0; i < n; i++) {
				printf("%s\n", ans[i]);
		}
		puts("");
	}

	
	
	return 0;
}
