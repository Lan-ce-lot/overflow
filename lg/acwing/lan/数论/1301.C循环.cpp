#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a, b, c, d, x, y;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
    while (cin >> a >> b >> c >> d, a | b | c | d) {
        /**
         * @e 1ll 不然31会溢出
         **/
        d = 1ll << d;   

        ll D = exgcd(c, d, x, y);
        if ((b - a) % D)
            puts("FOREVER");
        else {
            x *= (b - a) / D;
            y *= (b - a) / D;
            /**
             * @e x % (d / D), 要先mod一下，不然会变成负数
             **/
            cout << (x % (d / D) + d / D) % (d / D) << endl; 
        }
    }
}
