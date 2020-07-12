#include <cstdio> 
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 80;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

int w, h, x1, y1, x2, y2, step[N][N];
char board[N][N];
bool vis[N][N];
vector<int> vx1[N][N], vy1[N][N], vx2[N][N], vy2[N][N];

bool inside (int x, int y) {
	if (x >= 0 && y >= 0 && x <= w+1 && y <= h+1) return true;
	return false;
}

void init () {
	for (int y = 0; y <= h + 1; y++) {
		for (int x = 0; x <= w + 1; x++) {
			vx1[y][x].clear();
			vx2[y][x].clear();
			vy1[y][x].clear();
			vy2[y][x].clear();
			for (int i = 0; i < 4; i++) {
				int nx = x + dr[i], ny = y + dc[i];
				while (inside(nx, ny)) {
					if (board[ny][nx] == 'X') {
						vx2[y][x].push_back(nx);
						vy2[y][x].push_back(ny);
						break;
					} else {
						vx1[y][x].push_back(nx);
						vy1[y][x].push_back(ny);
					}
					nx = nx + dr[i]; 
					ny = ny + dc[i];
				}
			}
		}
	}
}

int bfs (int x1, int y1, int x2, int y2) {
	queue<int> qx, qy;
	int x = x1, y = y1, top = 0;
	qx.push(x); qy.push(y);
	step[y][x] = 0;
	vis[y][x] = true;
	while (!qx.empty()) {
		x = qx.front(); qx.pop();
		y = qy.front(); qy.pop();
		for (int i = 0; i < vx1[y][x].size(); i++) {
			int nx = vx1[y][x][i], ny = vy1[y][x][i];
			if (vis[ny][nx]) continue;
			qx.push(nx); qy.push(ny);
			vis[ny][nx] = true;
			step[ny][nx] = step[y][x] + 1;
		}
		for (int i = 0; i < vx2[y][x].size(); i++) {
			int nx = vx2[y][x][i], ny = vy2[y][x][i];
			if (ny == y2 && nx == x2) return step[y][x] + 1;
		}
	}
	return -1;
}

int main () {
	int kase = 1;
	while (scanf("%d%d", &w, &h) && w + h != 0) {
		getchar();
		memset(board, 0, sizeof(board));
		for (int i = 1; i <= h; i++) {
			gets(board[i] + 1);
		}
		init();
		printf("Board #%d:\n", kase);
		int t = 1;
		while (scanf("%d%d%d%d", &x1, &y1, &x2, &y2) && x1+y1+x2+y2 != 0) {
			memset(vis, 0, sizeof(vis));
			int ans = bfs(x1, y1, x2, y2);
			if (ans != -1) printf("Pair %d: %d segments.\n", t, ans);
			else printf("Pair %d: impossible.\n", t);
			t++;
		}
		kase++;
		printf("\n");
	}
	return 0;
}

