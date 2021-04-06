#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
#define ll long long
struct node {
    ll ne, to, v;
} G[N];
ll n, h[N], tot, d1[N], d2[N], maxx = -1;
void add(int a, int b, int v) { G[tot] = {h[a], b, v}, h[a] = tot++; }
void dfs(int u, int fa) {
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to != fa) {
            dfs(to, u);
            maxx = max(maxx, d1[to] + G[i].v + d1[u]);
            d1[u] = max(d1[u], d1[to] + G[i].v);
        }
    }
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    ll res = 11ll * maxx + (maxx - 1ll) * maxx / 2;
    cout << res << endl;
}