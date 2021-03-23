#include <bits/stdc++.h>

using namespace std;
int n, a[1005], ans, d;
bool f[105][10005];
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], d = gcd(d, a[i]);
    f[0][0] = 1;
    if (d != 1)
        cout << "INF" << endl;
    else {
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 10005; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= a[i]) f[i][j] |= f[i][j - a[i]];
            }
        for (int i = 0; i < 10005; i++)
            if (!f[n][i]) ans++;
        cout << ans << endl;
    }
}