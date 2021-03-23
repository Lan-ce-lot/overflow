#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, ans, vis[25][25];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
typedef pair<int, int> PII;
#define x first
#define y second
char M[25][25];
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && M[x][y] == '.';
}
void bfs() {
    queue<PII> Q;
    memset(vis, 0, sizeof vis);
    Q.push({sx, sy});
    ans = vis[sx][sy] = 1;
    while (Q.size()) {
        PII top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = top.x + dir[i][0], y = top.y + dir[i][1];
            if (check(x, y))
                vis[x][y] = 1, Q.push({x, y}), ans++;
        }
    }
}

int main() {
    while (cin >> m >> n, n || m) {
        for (int i = 1; i <= n; i++)
            cin >> M[i] + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (M[i][j] == '@') sx = i, sy = j;
        bfs();
        cout << ans << endl;
    }
}