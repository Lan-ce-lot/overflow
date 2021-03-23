#include <bits/stdc++.h>
using namespace std;

int n, m, num[1005], f[1005];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= num[i]; j--) {
            f[j] += f[j - num[i]];
        }
    }
    cout << f[m] << endl;
}