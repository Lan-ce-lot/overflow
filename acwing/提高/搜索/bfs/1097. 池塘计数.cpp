#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, ans = 0;
char maze[1004][1004];
bool vis[1004][1004];
int dir[8][2] = {   -1, -1, -1, 0, -1, 1,
                    0, -1, 0, 1,
                    1, -1, 1, 0, 1, 1};
                    
                    
struct node{
	int x, y;
};      

bool test(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M && vis[x][y] == 0 && maze[x][y] == 'W');
}

          
void bfs(int x, int y) {
	queue<node> Q;
	vis[x][y] = 1;
	Q.push({x, y});
	while (!Q.empty()) {
		node top = Q.front();
		Q.pop();
		
		for (int i = 0; i < 8; i++) {
			int xx = top.x + dir[i][0], yy = top.y + dir[i][1];
			if (test(xx, yy)) {
				vis[xx][yy] = 1;
				Q.push({xx, yy});
			}
		}
	}
	ans++;
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", maze[i]);
    }
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < M; j++) {
    		if (!vis[i][j] && maze[i][j] == 'W')
    			bfs(i, j);
		}
	}
	printf("%d\n", ans);

}
