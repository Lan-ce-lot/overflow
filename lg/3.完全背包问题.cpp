#include  <bits/stdc++.h>
using namespace std;
int n, m, v[1005], w[1005], f[1005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }1
    cout << f[m] << endl;
}