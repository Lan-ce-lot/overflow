#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, a[100005], c[100005];
ll gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int step = 1, flag = 0;
    for (int i = 1; i < n; i++) {
        c[i] = a[i + 1] - a[i];
        if (c[i] != 0) flag = 1;
    }
    if (!flag) {
        cout << n << endl;
    } else {
        step = c[1];
        for (int i = 2; i < n; i++) {
            step = gcd(step, c[i]);
        }
        cout << (a[n] - a[1]) / step + 1 << endl;
    }
}