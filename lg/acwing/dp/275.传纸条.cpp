#include <bits/stdc++.h>

using namespace std;

int ma[1005][1005], n, m, f[1005][55][55];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ma[i][j];
        }
    }
    for (int k = 2; k <= n + m; k++) {
        for (int x1 = 1; x1 < k; x1++) {
            for (int x2 = 1; x2 < k; x2++) {
                int &v = f[k][x1][x2];
                int tmp = ma[x1][k - x1];
                if (x1 != x2) tmp += ma[x2][k - x2];
                v = max(v, f[k - 1][x1][x2 - 1]);
                v = max(v, f[k - 1][x1][x2]);
                v = max(v, f[k - 1][x1 - 1][x2 - 1]);
                v = max(v, f[k - 1][x1 - 1][x2]);
                v += tmp;
            }
        }
    }
    printf("%d\n", f[n + m][n][n]);
}