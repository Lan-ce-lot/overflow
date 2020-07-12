#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, N, M, ans = 0;
int maze[1004][1004];
bool vis[1004][1004];
int dir[8][2] = {   -1, -1, -1, 0, -1, 1,
                    0, -1, 0, 1,
                    1, -1, 1, 0, 1, 1};

struct node{
	int x, y;
};

bool test(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < n);
}

void bfs(int x, int y, bool &has_u, bool &has_l) {
	queue<node> Q;
	vis[x][y] = 1;
	Q.push({x, y});
	while (!Q.empty()) {
		node top = Q.front();
		Q.pop();

		for (int i = 0; i < 8; i++) {
			int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
			if (test(xx, yy) && maze[xx][yy] == maze[top.x][top.y] && !vis[xx][yy]) {
				vis[xx][yy] = 1;
				Q.push({xx, yy});
			}
			if (test(xx, yy) && maze[xx][yy] < maze[top.x][top.y]) has_l = 1;
			if (test(xx, yy) && maze[xx][yy] > maze[top.x][top.y]) has_u = 1;
		}
	}
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &maze[i][j]);

    int f = 0, g = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                bool has_u = 0, has_l = 0;
                bfs(i, j, has_u, has_l);
                if (has_u && !has_l) g++;
                if (!has_u && has_l) f++;
                if (!has_u && !has_l) g++, f++;
            }
        }
    }
    printf("%d %d\n", f, g);
}
