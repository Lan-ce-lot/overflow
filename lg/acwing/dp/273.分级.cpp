#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, a[2005], b[2005], f[2005][2005];
int work() {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        int minv = INF;
        for (int j = 1; j <= n; j++) {
            minv = min(minv, f[i - 1][j]);
            f[i][j] = minv + abs(a[i] - b[j]);
        }
    }
    int res = INF;
    for (int i = 1; i <= n; i++) {
        res = min(res, f[n][i]);
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = work();
    reverse(a + 1, a + n + 1);
    res = min(res, work());
    printf("%d\n", res);
}