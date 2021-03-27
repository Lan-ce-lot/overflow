#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
ll n;
struct node {
    ll h, ind, v;
} q[N], t[N];
void mer(int l, int r) {
    if (l >= r) return;
    int m = l + r >> 1;
    mer(l, m), mer(m + 1, r);
    int k = l, i = l, j = m + 1;
    while (i <= m && j <= r)
        if (q[i].h <= q[j].h)
            t[k++] = q[i++];
        else
            t[k++] = q[j++];
    while (i <= m) t[k++] = q[i++];
    while (j <= r) t[k++] = q[j++];
    for (i = l; i < k; i++) q[i] = {t[i].h, i, t[i].v + abs(t[i].ind - i)};
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> q[i].h, q[i].ind = i;
    mer(1, n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += (q[i].v + 1) * q[i].v / 2;
    cout << ans << endl;
}