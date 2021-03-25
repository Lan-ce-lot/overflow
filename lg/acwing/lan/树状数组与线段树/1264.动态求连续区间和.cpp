#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int n, m, a, t[N], b, k;
int lowbit(int x) { return x & -x; }
void add(int u, int v) {
    for (; u < N; u += lowbit(u)) t[u] += v;
}
int ask(int u) {
    int res = 0;
    for (; u; u -= lowbit(u)) res += t[u];
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a, add(i, a);
    for (int i = 0; i < m; i++) {
        cin >> k >> a >> b;
        if (k)
            add(a, b);
        else
            cout << ask(b) - ask(a - 1) << endl;
    }
}
