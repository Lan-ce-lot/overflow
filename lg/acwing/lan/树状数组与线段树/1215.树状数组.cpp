#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
typedef long long ll;
ll n, t[N], a[N], sum[N];
int lowbit(int x) { return x & -x; }

void add(int u, int v) {
    for (; u < N; u += lowbit(u)) t[u] += v;
}

ll ask(int u) {
    ll res = 0;
    for (; u; u -= lowbit(u)) res += t[u];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] += ask(N - 1) - ask(a[i]), add(a[i], 1);
    memset(t, 0, sizeof t);
    for (int i = n; i > 0; i--) sum[i] += ask(a[i] - 1), add(a[i], 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += sum[i] * (sum[i] + 1) / 2;
    cout << ans << endl;
}