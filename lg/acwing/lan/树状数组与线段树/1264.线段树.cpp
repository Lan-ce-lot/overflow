#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int n, m, a, b, k, d[N];

struct node {
    ll v, l, r;
} T[N * 2];
void build(int u, int l, int r) {
    T[u].l = l, T[u].r = r;
    if (l == r) {
        T[u].v = d[l];
        return;
    }
    int m = l + r >> 1;
    build(u << 1, l, m);
    build(u << 1 | 1, m + 1, r);
    T[u].v = T[u << 1].v + T[u << 1 | 1].v;
}

void update(int u, int p, int v) {
    if (T[u].l == T[u].r) {
        T[u].v += v;
        return;
    }
    int m = T[u].l + T[u].r >> 1;
    if (p <= m)
        update(u << 1, p, v);
    else
        update(u << 1 | 1, p, v);
    T[u].v = T[u << 1].v + T[u << 1 | 1].v;
}

int query(int u, int l, int r) {
    if (l <= T[u].l && T[u].r <= r) return T[u].v;
    int m = T[u].l + T[u].r >> 1;
    if (r <= m) return query(u << 1, l, r);
    if (l > m) return query(u << 1 | 1, l, r);
    return query(u << 1, l, m) + query(u << 1 | 1, m + 1, r);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> k >> a >> b;
        if (k)
            update(1, a, b);
        else
            cout << query(1, a, b) << endl;
    }
}
