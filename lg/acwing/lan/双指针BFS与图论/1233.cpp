#include <bits/stdc++.h>

using namespace std;
int n, dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}, c1, c2;
const int N = 1005;
struct node {
    int x, y;
};
char M[N][N];
int vis[N][N];
set<int> S;
bool check(int x, int y) { return min(x, y) >= 1 && max(x, y) <= n; }
void dfs(int x, int y, int f) {
    int flag = 0;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (check(xx, yy) && !vis[xx][yy]) 
            if (M[xx][yy] == '.') flag++;
            else if(M[xx][yy] == '#') dfs(xx, yy, f);
    }
    if (!flag) S.insert(f);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> M[i] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!vis[i][j] && M[i][j] == '#') dfs(i, j, c1++);
    cout << c1 - S.size() << endl;
}
