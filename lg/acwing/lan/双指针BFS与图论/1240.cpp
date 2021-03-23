#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, a[100005], ans, d[100005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dep = 0;

    for (int l = 1; l <= n;) {
        int r = l + (1 << dep) - 1;
        while (l <= r && l <= n) d[dep] += a[l++];
        l = r + 1;
        dep++;
    }
    cout << (max_element(d, d + dep) - d) + 1 << endl;
}