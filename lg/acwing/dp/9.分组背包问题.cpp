#include <bits/stdc++.h>
using namespace std;
int N, V, k, w[1005][1005], v[1005][1005], s[1005], f[1005];
int main() {
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= 0; j--) {
            for (int k = 1; k <= s[i]; k++) {
                if (j >= v[i][k]) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }
    cout << f[V] << endl;
}