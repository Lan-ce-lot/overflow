#include <bits/stdc++.h>

using namespace std;
int t, n, m, vis[205][205], sx, sy, ex, ey;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char M[205][205];

struct node {
    int x, y, s;
};

bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && vis[x][y] == 0 &&
           M[x][y] != '#';
}
int bfs() {
    memset(vis, 0, sizeof vis);
    queue<node> Q;
    Q.push({sx, sy, 0});
    while (Q.size()) {
        node top = Q.front();
        Q.pop();
        if (top.x == ex && top.y == ey) return top.s;
        for (int i = 0; i < 4; i++) {
            int x = top.x + dir[i][0], y = top.y + dir[i][1];
            if (check(x, y)) vis[x][y] = 1, Q.push({x, y, top.s + 1});
        }
    }
    return -1;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> M[i] + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (M[i][j] == 'S') sx = i, sy = j;
                if (M[i][j] == 'E') ex = i, ey = j;
            }

        if (bfs() == -1)
            puts("oop!");
        else
            cout << bfs() << endl;
    }
}