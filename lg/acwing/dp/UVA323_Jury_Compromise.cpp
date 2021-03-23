#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], p[1005], d[1005], f[205][25][805], tot = 0;
void out(int i, int j, int k)
{
    int ans[25], cnt = 0, P = 0, D = 0;
    while (j) {
        if (f[i][j][k] == f[i - 1][j][k])
            i--;
        else {
            ans[++cnt] = i;
            k -= (p[i] - d[i]);
            P += p[i];
            D += d[i];
            j--, i--;
        }
    }
    printf("Jury #%d\n", ++tot);
    printf("Best jury has value %d for prosecution and value %d for defence:\n", P, D);
    for (int u = cnt; u >= 1; u--)
        printf(" %d", ans[u]);
    printf("\n\n");
}
int main()
{
    while (cin >> n >> m, n | m) {
        for (int i = 1; i <= n; i++) {
            cin >> p[i] >> d[i];
        }
        memset(f, -0x3f, sizeof f);
        f[0][0][400] = 0;
        //
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= 800; k++) {
                    f[i][j][k] = f[i - 1][j][k];
                    if (j < 1)
                        continue;
                    int t = k - p[i] + d[i];
                    if (t < 0 || t > 800)
                        continue;
                    f[i][j][k] = max(f[i - 1][j - 1][t] + p[i] + d[i], f[i][j][k]);
                }
            }
        }
        for (int i = 0; i <= 400; i++) {
            if (f[n][m][400 - i] >= 0 || f[n][m][i + 400] >= 0) {
                if (f[n][m][400 - i] > f[n][m][400 + i]) {
                    out(n, m, 400 - i);
                    break;
                } else {
                    out(n, m, 400 + i);
                    break;
                }
            }
        }
    }
}
