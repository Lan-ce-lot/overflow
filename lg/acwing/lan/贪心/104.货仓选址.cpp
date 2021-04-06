#include <bits/stdc++.h>

using namespace std;
int n, a[100005], ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n / 2; i++) ans += (a[n - i + 1] - a[i]);
    cout << ans << endl;
}