#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
#define ll long long
struct node {
    ll ne, to, v;
} G[N];
ll n, h[N], tot, d1[N], d2[N], maxx = -1;
void add(int a, int b, int v) { G[tot] = {h[a], b, v}, h[a] = tot++; }
void dfs(int u, int f, int sum) {
    d1[u] = sum;
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (f != to) dfs(to, u, sum + G[i].v);
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
    dfs(1, -1, 0);
    int u = max_element(d1 + 1, d1 + n + 1) - d1;
    dfs(u, -1, 0);
    u = max_element(d1 + 1, d1 + n + 1) - d1;
    maxx = d1[u];
    ll res = 11ll * maxx + (maxx - 1ll) * maxx / 2;
    cout << res << endl;
}