#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n, m, q;
ll t, r, c, z, ans;
ll a[2005][2005], b[2005][2005];
 
void inserted(int x1, int y1, int x2, int y2, int k) {
    b[x1][y1] = (b[x1][y1] + k) % mod;
    b[x1][y2 + 1] = (b[x1][y2 + 1] - k) % mod;
    b[x2 + 1][y1] = (b[x2 + 1][y1] - k) % mod;
    b[x2 + 1][y2 + 1] = (b[x2 + 1][y2 + 1] + k) % mod;
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
    	cin >> r >> c >> z;
        inserted(1, c, n, c, z);
        inserted(r, 1, r, m, z);
        inserted(r, c, r, c, -z);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = (ans + (b[i][j] * (i + j)) % mod) % mod;
    cout << ans << endl;
}
 
int main() {
    solve();
}
