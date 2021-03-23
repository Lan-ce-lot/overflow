#include<bits/stdc++.h>
using namespace std;
int n, a[1005], f[1005][1005], s[1005];
int dp(int l, int r) {
    if (l >= r) return 0;
    int& ans = f[l][r];
    if (ans != -1) return ans;
    ans = 0x3f3f3f3f;
    for (int k = l; k < r; k++) {
        ans = min(dp(l, r), dp(l, k) + dp(k + 1, r) + s[r] - s[l - 1]);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    memset(f, -1, sizeof f);
    cout << dp(1, n) << endl;
}