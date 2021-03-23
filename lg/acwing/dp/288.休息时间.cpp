#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, INF = 0x3f3f3f3f;
int n, m, u[N], f[2][N][2];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }
    memset(f, -0x3f, sizeof f);
    f[1][0][0] = f[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i & 1][j][0] = max(f[i - 1 & 1][j][0], f[i - 1 & 1][j][1]);
            f[i & 1][j][1] = -INF;
            if (j)
                f[i & 1][j][1] =
                    max(f[i - 1 & 1][j - 1][0], f[i - 1 & 1][j - 1][1] + u[i]);
        }
    }
    int res = f[n & 1][m][0];
    memset(f, -0x3f, sizeof f);
    f[1][0][0] = 0, f[1][1][1] = u[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i & 1][j][0] = max(f[i - 1 & 1][j][0], f[i - 1 & 1][j][1]);
            f[i & 1][j][1] = -INF;
            if (j)
                f[i & 1][j][1] =
                    max(f[i - 1 & 1][j - 1][0], f[i - 1 & 1][j - 1][1] + u[i]);
        }
    }
    res = max(f[n & 1][m][1], res);
    cout << res << endl;
}