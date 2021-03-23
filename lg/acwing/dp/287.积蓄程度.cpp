#include <bits/stdc++.h>
using namespace std;

struct node {
    int ne, to, e;
} G[400010];
const int INF = 0x3f3f3f3f;
int t, n, h[400010], tot, de[400010], d[400010], f[400010];

void dp(int u, int fa) {
    d[u] = 0;
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to == fa) continue;
        dp(to, u);
        if (de[to] == 1)
            d[u] += G[i].e;
        else
            d[u] += min(G[i].e, d[to]);
    }
}

void dfs(int u, int fa) {
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to == fa) continue;
        if (de[to] == 1)
            f[to] = min(G[i].e, f[u] - G[i].e);
        else {
            f[to] = d[to] + min(G[i].e, f[u] - min(G[i].e, d[to]));
            dfs(to, u);
        }
    }
}

void add(int a, int b, int c) {
    G[tot] = {h[a], b, c};
    h[a] = tot++;
}

int main() {
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        memset(h, -1, sizeof h), tot = 0;
        memset(de, 0, sizeof de);
        for (int i = 1; i < n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
            add(b, a, c);
            de[a]++, de[b]++;
        }
        int root = 1;
        while (root <= n && de[root] == 1) root++;

        if (root > n) {
            cout << G[0].e << endl;
            continue;
        }
        dp(root, -1);
        f[root] = d[root];
        dfs(root, -1);
        int res = 0;
        for (int i = 1; i <= n; i++) res = max(res, f[i]);

        printf("%d\n", res);
    }
}
