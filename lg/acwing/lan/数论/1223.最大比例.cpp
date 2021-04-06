#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll n, a[N], U[N], D[N];
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
/**
 * 更相减损术
 * 相除是因为p^(a - b) = p^a / p^b
 * @param {
 * a: p^a
 * b: p^b
 * }
 * @return if b == 1 then return a
 *         else return gcd_sub(b, a / b)
 */
ll gcd_sub(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 1) return a;
    return gcd_sub(b, a / b);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int l = unique(a, a + n) - a;
    for (int i = 1; i < l; i++) {
        ll d = gcd(a[i], a[0]);
        D[i - 1] = a[0] / d;
        U[i - 1] = a[i] / d;
    }

    ll up = U[0], down = D[0];
    for (int i = 1; i < l - 1; i++)
        up = gcd_sub(up, U[i]), down = gcd_sub(down, D[i]);

    cout << up << '/' << down << endl;
}