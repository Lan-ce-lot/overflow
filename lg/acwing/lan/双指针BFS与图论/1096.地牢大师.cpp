#include <bits/stdc++.h>
using namespace std;
int L, C, R, vis[105][105][105];
char M[105][105][105];
int dir[6][3] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                 {0, -1, 0}, {0, 0, -1}, {0, 0, 1}};

struct node {
    int x, y, z, s;
} S, E;
bool check(node t) {
    return t.x >= 1 && t.x <= L && t.y >= 1 && t.y <= C && t.z >= 1 &&
           t.z <= R && M[t.x][t.y][t.z] != '#' && !vis[t.x][t.y][t.z];
}
int bfs() {
    memset(vis, 0, sizeof vis);
    queue<node> Q;
    Q.push(S);
    vis[S.x][S.y][S.z] = 1;
    while (Q.size()) {
        node top = Q.front();
        Q.pop();
        if (top.x == E.x && top.y == E.y && top.z == E.z) return top.s;
        for (int i = 0; i < 6; i++) {
            node t = {top.x + dir[i][0], top.y + dir[i][1], top.z + dir[i][2],
                      top.s + 1};
            if (check(t))
                vis[t.x][t.y][t.z] = 1, Q.push(t);
        }
    }
    return -1;
}
int main() {
    while (cin >> L >> C >> R, L | C | R) {
        for (int i = 1; i <= L; i++)
            for (int j = 1; j <= C; j++) cin >> M[i][j] + 1;
        for (int i = 1; i <= L; i++)
            for (int j = 1; j <= C; j++)
                for (int k = 1; k <= R; k++) {
                    if (M[i][j][k] == 'S') S = {i, j, k, 0};
                    if (M[i][j][k] == 'E') E = {i, j, k, 0};
                }
        int res = bfs();
        if (~res)
            printf("Escaped in %d minute(s).\n", res);
        else
            puts("Trapped!");
    }
}