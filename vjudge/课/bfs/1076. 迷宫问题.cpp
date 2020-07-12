#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second

int n, N, M, ans = 0;
int maze[1004][1004];
bool vis[1004][1004];
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
PII pre[1004][1004];
struct node{
	int x, y;
};

bool test(int x, int y) {return (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y] && !maze[x][y]);}

void bfs(int x, int y) {
	queue<node> Q;
	vis[x][y] = 1;
	Q.push({x, y});
	while (!Q.empty()) {
		node top = Q.front();
		Q.pop();
		if (top.x == 0 && top.y == 0) return;
		for (int i = 0; i < 4; i++) {
            int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
            if (test(xx, yy)) {
                vis[xx][yy] = 1;
                Q.push({xx, yy});
                pre[xx][yy] = {top.x, top.y};
            }
		}
	}
}

int main() {
//    scanf("%d", &n);
    n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    bfs(n - 1, n - 1);// 倒过来
    PII path(0, 0);
    while (true)
    {
        printf("(%d, %d)\n", path.x, path.y);
        if (path.x == n - 1 && path.y == n - 1) break;
        path = pre[path.x][path.y];
    }
}
