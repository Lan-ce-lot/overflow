#include <bits/stdc++.h>
using namespace std;
int f[1005][1005];
int main() {
    string str = "";
    getline(cin, str);
    int n = str.size();
    str = ' ' + str;
    for (int i = 1; i <= n; i++) f[i][i] = 1;
    int Max = 1;
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l <= n - len; l++) {
            int r = l + len;
            if (str[l] == str[r])
                if (f[l + 1][r - 1] == r - l - 1) {
                    f[l][r] = f[l + 1][r - 1] + 2;
                    if (f[l][r] > Max) Max = f[l][r];
                }
        }
    }
    cout << Max << endl;
    return 0;
}
