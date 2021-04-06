#include <bits/stdc++.h>

using namespace std;
int n, m, k, a, f[1 << 20], b[105];

int main() {
    cin >> n >> m >> k;
    m = (1 << m) - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) cin >> a,b[i] |= (1 << a - 1);
    memset(f + 1, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            f[j] = min(f[j], f[j & (~b[i])] + 1);
    if (f[m] == 0x3f3f3f3f)
        puts("-1");
    else
        cout << f[m] << endl;
}