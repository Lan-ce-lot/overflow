#include <bits/stdc++.h>

using namespace std;
string s, r;
int n, f[1005][1005];
map<char, int> M{{'[', 1}, {']', -1}, {'(', 1}, {')', -1}};
string re(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        s[i] = M[s[i]];
    }
    return s;
}
int main() {
    cin >> s;
    n = s.size();

    s = ' ' + s;
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (len == 1)
                f[r][r] = 1;
            else {
                f[l][r] = 0x3f3f3f3f;
                if (s[l] == '[' && s[r] == ']' || s[l] == '(' && s[r] == ')')
                    f[l][r] = min(f[l][r], f[l + 1][r - 1]);
                for (int k = l; k < r; k++) {
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
                }
            }         
        }
    }
    cout << f[1][n] << endl;
}