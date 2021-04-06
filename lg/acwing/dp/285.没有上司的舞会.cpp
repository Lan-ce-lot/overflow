#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int ne, to, e;
} G[10005];
int head[10005], tot, h[10005], f[10005], n;
int dp[10005][2];
void dfs(int u, int f) {
    dp[u][0] = 0, dp[u][1] = h[u];
    for (int i = head[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to != f) dfs(to, u);
        dp[u][0] += max(dp[to][1], dp[to][0]);
        dp[u][1] += dp[to][0];
    }
}
void add(int u, int v, int w) {
    G[tot] = {head[u], v, w};
    head[u] = tot++;
}

int main() {
    cin >> n;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    memset(f, 0, sizeof f);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        f[a] = b;
        add(b, a, 1);
    }
    int root = 1;
    while (f[root]) {
        root = f[root];
    }
    dfs(root, -1);
    cout << max(dp[root][0], dp[root][1]);
}