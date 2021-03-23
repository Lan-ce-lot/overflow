#include <bits/stdc++.h>
const int MOD = 1e9;
using namespace std;
typedef long long ll;
string str;
int n;
ll f[1005][1005];
int main() {
    cin >> str;
    n = str.size();
    str = ' ' +str;
    if (n % 2 == 0) cout << 0 << endl;
    else {
        for(int len = 1; len <= n; len += 2) 
            for (int l = 1; l + len - 1 <= n; l ++) {
                int r = l + len - 1;
                if (len == 1) f[l][r] = 1;
                else if (str[l] == str[r]) {
                    for (int k = l; k < r; k += 2)
                        if (str[k] == str[r])
                            f[l][r] = (f[l][r] + f[l][k] * f[k + 1][r - 1]) % MOD;
                }
            }
        cout << f[1][n] << endl;
    }
}