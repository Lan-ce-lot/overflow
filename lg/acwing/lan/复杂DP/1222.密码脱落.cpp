#include <bits/stdc++.h>

using namespace std;
string s, s_r;
int ans = 0, f[1005][1005], n;
int main() {
    cin >> s;
    n = s.size();
    s_r = s;
    reverse(s_r.begin(), s_r.end());
    s = ' ' + s, s_r = ' ' + s_r;
    // cout << s << s_r << n <<endl;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            if (s[i] == s_r[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    cout << n - f[n][n] << endl;
}