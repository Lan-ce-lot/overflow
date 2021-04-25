#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e2 + 5;
int a[N], b[N], f[2][N][N * N];
int main()
{
    int n, tot1 = 0, tot2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i], tot2 += b[i];
    memset(f, 1 << 7, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        tot1 += a[i];
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= tot1; k++) {
                f[i & 1][j][k] = f[(i - 1) & 1][j][k];
                if (j && k >= a[i])
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[(i - 1) & 1][j - 1][k - a[i]] + b[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        double ans = 0.0;
        for (int j = 0; j <= tot1; j++)
            ans = max(ans, min(1.0 * j, f[n & 1][i][j] / 2.0 + tot2 / 2.0));
        printf("%.6f\n", ans);
    }
}
