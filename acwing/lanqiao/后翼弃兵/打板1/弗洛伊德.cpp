#include<iostream>
#include <cstring>
using namespace std;
const int N = 1e3 + 5;
int G[N][N], dis[N][N];
int n, m, k;
int main() {
    cin >> n >> m >> k;
    memset(G, 0x3f, sizeof G);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = min(G[a][b], c);
    }
    for (int i = 0; i <= n; i++) G[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (G[a][b] > 0x3f3f3f3f / 2) puts("impossible");
        else printf("%d\n", G[a][b]);
    }
    return 0;
}