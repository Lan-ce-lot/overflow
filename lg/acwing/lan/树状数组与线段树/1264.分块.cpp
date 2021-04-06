#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, m, a, b, k, dd[N];
ll sum[N], add[N], L[N], R[N], pos[N], t;
void change(int l, int r, ll d) {
    int p = pos[l], q = pos[r];
    if (p == q) {
        for (int i = l; i <= r; i++) dd[i] += d;
        sum[p] += d * (r - l + 1);
    } else {
        for (int i = p + 1; p <= q - 1; i++) add[i] += d;
        for (int i = l; i <= R[p]; i++) dd[i] += d;
        sum[p] += d * (R[p] - l + 1);
        for (int i = L[q]; i <= r; i++) dd[i] += d;
        sum[q] += d * (r - L[q] + 1);
    }
}
ll ask(int l, int r) {
    int p = pos[l], q = pos[r];
    ll ans = 0;
    if (p == q) {
        for (int i = l; i <= r; i++) ans += dd[i];
        ans += add[p] * (r - l + 1);
    } else {
        for (int i = p + 1; i <= q - 1; i++)
            ans += sum[i] + add[i] * (R[i] - L[i] + 1);
        for (int i = l; i <= R[p]; i++) ans += dd[i];
        ans += add[p] * (R[p] - l + 1);
        for (int i = L[q]; i <= r; i++) ans += dd[i];
        ans += add[q] * (r - L[q] + 1);
    }
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> dd[i];
    t = sqrt(n);
    for (int i = 1; i <= t; i++) L[i] = (i - 1) * sqrt(n) + 1, R[i] = i * sqrt(n);
    if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;

    for (int i = 1; i <= t; i++)
        for (int j = L[i]; j <= R[i]; j++) pos[j] = i, sum[i] += dd[j];
    for (int i = 0; i < m; i++) {
        cin >> k >> a >> b;
        if (k)
            change(a, a, b);
        else
            cout << ask(a, b) << endl;
    }
}
