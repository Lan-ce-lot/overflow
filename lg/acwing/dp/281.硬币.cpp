#include <bits/stdc++.h>
using namespace std;
int n, m, A[1000005], C[1000005], f[1000005], ans, cnt, w[100005], g[100005];

bool vis[100005];
int main() {
    while (cin >> n >> m, n | m) {
        memset(f, 0, sizeof f);
        memset(vis, 0, sizeof vis);
        cnt = ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> C[i];
        }
        f[0] = 1;
        for (int i = 1; i <= n; i ++) {
            memset(g, 0, sizeof g);
            for (int j = 1; j <= m; j++) {
                if (!f[j] && f[j - A[i]] && g[j - A[i]] < C[i]) {
                    f[j] = 1;
                    g[j] = g[j - A[i]] + 1;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if (f[i]) {
                ans ++;
            }
        }
        cout << ans << endl;
    }
}