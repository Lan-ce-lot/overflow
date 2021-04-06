#include <bits/stdc++.h>
using namespace std;
int n, m, v[1005], w[1005], f[1005][1005];
int main() {
    cin >> n >> m;
    for (int i = 1; i<= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j]);
            if (v[i] <= j) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << f[n][m] << endl;
}