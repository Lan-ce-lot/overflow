#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
ll n, v[N];

struct node {
    ll ne, to;
} G[N];
ll h[N], tot, d[N];
void add(int a, int b) { G[tot] = {h[a], b}, h[a] = tot++; }

void dp(int u, int f) {
    d[u] = v[u];
    for (int i = h[u]; ~i; i = G[i].ne) {
        int to = G[i].to;
        if (to != f) {
            dp(to, u);
            d[u] += max(0ll, d[to]);
        }
    }
}
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dp(1, -1);
    cout << *max_element(d + 1, d + n + 1) << endl;
}