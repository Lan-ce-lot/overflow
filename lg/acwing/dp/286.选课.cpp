#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
    int ne, to, v;
} G[1005];
int h[1005], tot, f[1005][1005], w[1005];

void dp(int u) {
    f[u][0] = 0;
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        dp(to);
        for (int j = m; j; j--)
            for (int k = 1; k <= j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[to][k]);
    }
    for (int i = m; i; i--) f[u][i] = f[u][i - 1] + w[u];
}

void add(int a, int b, int v) {
    G[tot] = {h[a], b, v};
    h[a] = tot++;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> w[i];
        add(a, i, 1);
    }
    m++;
    dp(0);
    cout << f[0][m] << endl;
}