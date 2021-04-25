#include <iostream>
#include <cstring>
using namespace std;
int n, m;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int N = 1e3 + 5;

int G[N][N], dis[maxn], vis[maxn];
int dj() {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[1] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && (u == -1 || dis[j] < dis[u])) u = j;
        }
        vis[u] = 1;
        for (int j = 1; j <= n; j++) {
            dis[j] = min(dis[j], dis[u] + G[u][j]);
        }
    }
    if (dis[n] != INF) return dis[n];
    else return -1;
}
int main() {
    cin >> n >> m;
    memset(G, 0x3f, sizeof G);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = min(G[a][b], c);
    }
    cout << dj() << endl;
    return 0;
}