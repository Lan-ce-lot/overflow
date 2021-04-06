#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int n, m, a[N];
struct node {
    int v, l, r;
} T[N * 4];
void build(int u, int l, int r) {
    T[u].l = l, T[u].r = r;
    if (l == r) {
        T[u].v = a[l];
        return;
    }
    int m = l + r >> 1;
    build(u << 1, l, m);
    build(u << 1 | 1, m + 1, r);
    T[u].v = max(T[u << 1].v, T[u << 1 | 1].v);
}
int query(int u, int l, int r) {
    if (l <= T[u].l && T[u].r <= r) return T[u].v;
    int m = T[u].l + T[u].r >> 1;
    if (m >= r) return query(u << 1, l, r);
    if (m < l) return query(u << 1 | 1, l, r);
    return max(query(u << 1, l, m), query(u << 1 | 1, m + 1, r));
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r));
    }
}
