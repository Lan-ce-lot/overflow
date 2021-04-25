#include <bits/stdc++.h>

using namespace std;
int n, ans, f[14];
int main() {
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}
