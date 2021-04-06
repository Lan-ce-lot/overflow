#include <bits/stdc++.h>

using namespace std;

int n, dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}, c1 = 1, c2;
const int N = 1005;
struct node {
    int x, y;
};
char M[N][N];
int vis[N][N];
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
    // return min(x, y) >= 1 && max(x, y) <= n;
}

void dfs(int x, int y, int f) {
    vis[x][y] = f;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (check(xx, yy) && !vis[xx][yy] && M[xx][yy] == '#') dfs(xx, yy, f);
    }
}
void bfs() {
    queue<node> Q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (M[i][j] == '.') Q.push({i, j});
    while (Q.size()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = top.x + dir[i][0], y = top.y + dir[i][1];
            if (check(x, y) && M[x][y] == '#') M[x][y] = '.', vis[x][y] = 0;
        }
    }
}
set<int> S;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> M[i] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (M[i][j] == '#' && vis[i][j] == 0) dfs(i, j, c1++);
    bfs();
    cout << c1 << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout <<M[i][j] << ' ';
        puts("");
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (M[i][j] == '#' && vis[i][j] != 0) S.insert(vis[i][j]);
    cout << c1 - 1 - S.size() << endl;
}

/*
3
...
.##
..#
*/