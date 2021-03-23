#include <bits/stdc++.h>

using namespace std;
string s, s_r;
int ans = 0, f[1005][1005], n;
int main() {
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) f[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            f[l][r] = max(f[l][r - 1], f[l + 1][r]);
            if (s[l] == s[r]) f[l][r] = max(f[l][r], f[l + 1][r - 1] + 2);
        }
    }
    cout << n - f[1][n] << endl;
}