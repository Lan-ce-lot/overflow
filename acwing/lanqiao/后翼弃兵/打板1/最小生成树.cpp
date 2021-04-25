#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3 + 5;
int dis[N], vis[N], n, m;
int G[N][N];
int dj() {

    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 1; j <= n;j ++) {
            if (!vis[j] && (u == -1 || dis[j] > dis[u])) u = j;
        }
        if (i && dis[u] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) res += dis[u];
        vis[u] = 1;
        for (int j = 1; j <= n; j++) {
            dis[j] = min(dis[j], G[u][j]);
        }

    }
    return res;
}
int main() {
    cin >> n >> m;

    memset(G, 0x3f, sizeof G);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = min(c, G[a][b]);
    }
    int ans = dj();
    if (ans > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        cout << ans << endl;
    return 0;
}