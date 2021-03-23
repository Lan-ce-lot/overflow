#include <bits/stdc++.h>
using namespace std;
char c[1005];
const int INF = 0x3f3f3f3f;
int a[1005], n, f[1005][1005], ans, m[1005][1005];
vector<int > Ans;
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> a[i];
        c[i + n] = c[i], a[i + n] = a[i];
    }
    for (int len = 1; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;
            if (len == 1) {
                f[l][r] = m[l][r] = a[l];continue;
            }
            f[l][r] = -INF, m[l][r] = INF;
            for (int k = l; k < r; k++) {
                if (c[k + 1] == 't') {
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
                    m[l][r] = min(m[l][r], m[l][k] + m[k + 1][r]);
                } else {
                    f[l][r] = max(f[l][r], 
                    max(f[l][k] * f[k + 1][r], 
                    max(f[l][k] * m[k + 1][r], 
                    max(m[l][k] * m[k + 1][r], m[l][k] * m[k + 1][r]))));
                    m[l][r] = min(m[l][r], 
                    min(f[l][k] * f[k + 1][r], 
                    min(f[l][k] * m[k + 1][r], 
                    min(m[l][k] * m[k + 1][r], m[l][k] * f[k + 1][r]))));
                }
            }
        }
    }
    ans = -INF;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i][i + n - 1]);
    }
        
    cout << ans << endl;
    for (int i = 1; i <= n; i++) if (ans == f[i][i + n - 1]) cout << i << ' ';
}