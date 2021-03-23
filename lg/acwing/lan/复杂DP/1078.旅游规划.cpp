#include <bits/stdc++.h>

using namespace std;
const int N = 4e5 + 5;
struct node {
    int ne, to;
} G[N];
int h[N], tot, a, b, f[N], n, ans = -0x3f3f3f3f, d[N], d2[N], up[N], p[N],
                              maxx = -0x3f3f3f3f;
vector<int> Ans;
void add(int a, int b) { G[tot] = {h[a], b}, h[a] = tot++; }

void dfs(int u, int fa) {
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to == fa) continue;
        dfs(to, u);
        int dis = d[to] + 1;
        if (dis > d[u]) {
            d2[u] = d[u], d[u] = dis;
            p[u] = to;
        } else if (dis > d2[u])
            d2[u] = dis;
    }
    maxx = max(maxx, d[u] + d2[u]);
}

void dfs1(int u, int fa) {
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to != fa) {
            up[to] = up[u] + 1;
            if (p[u] == to)
                up[to] = max(up[to], d2[u] + 1);
            else
                up[to] = max(up[to], d[u] + 1);
            dfs1(to, u);
        }
    }
}
int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) scanf("%d%d", &a, &b), add(a, b), add(b, a);
    dfs(0, -1);
    dfs1(0, -1);
    for (int i = 0; i < n; i++) {
        int d3[3] = {d[i], up[i], d2[i]};
        sort(d3, d3 + 3);
        if (d3[1] + d3[2] == maxx) printf("%d\n", i);
    }
}