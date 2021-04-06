#include <bits/stdc++.h>
using namespace std;
int n, f[4005];
int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i; j <= n; j++) {
            f[j] = (f[j] + f[j - i]) % 2147483648u;
        }
    }
    cout << f[n] << endl;
}