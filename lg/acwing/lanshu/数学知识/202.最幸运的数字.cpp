#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, s, mod;
ll mul(ll a, ll b) {
    ll res = 0, t = a % mod;
    while (b) {
        if (b & 1) res = (res + t) % mod;
        t = (t + t) % mod;
        b >>= 1;
    }
    return res;
}
ll qpow(ll a, ll x) {
    ll res = 1;
    while (x) {
        if (x & 1) res = mul(res, a);
        a = mul(a, a);
        x >>= 1;
    }
    return res;
}

ll phi(ll n) {
    ll res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res = res / n * (n - 1);
    return res;
}
int main() {
    while (cin >> n, n) {
        mod = n / __gcd(8ll, n) * 9ll;
        ll p = phi(mod), res = 1e18;
        for (ll i = 1; i * i <= p; i++) {
            if (p % i == 0) {
                if (qpow(10, i) == 1) res = min(res, i);
                if (qpow(10, p / i) == 1) res = min(res, p / i);
            }
        }
        printf("Case %lld: %lld\n", ++m, res == 1E18 ? 0 : res);
    }
}
