#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, t, d, x, y, a, b;
/**
 * 扩展欧几里得算法
 * a * x + b * y = gcd(a, b)
 * 不妨设 d = gcd(a, b)
 * a' = a / d
 * b' = b / d
 * 通过一组解(x0, y0)
 * 有通解
 * x = x0 + k * b'
 * y = y0 - k * a'
 * @param {    
 *     "a":
 *     "b":
 *     "x":
 *     "y":
 * }
 * @return if  b == 0 then return a
 *         else return exgcd(b, a % b, y, x)
 */
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
/**
 * 对于本题
 * 有x + b * d === y mod (n)
 * 要求解x + b * d = y + a * n
 * {
 * 长度 n
 * 飞的距离 d
 * 初始位置 x
 * 想去的地方 y
 * }
 * 最小的b即答案
 * 扩展欧几里得定理只能求 -an+bd = gcd(n,d)中的a和b
 * y-x应该为gcd(n,d)的整数倍
 * 否则无解
 * 若有解我们利用扩展欧几里得定理就可以求得-an+bd = gcd(n,d)中的a和b，
 * 然后将a和b扩大 (y-x)/gcd(n,d)倍
 * 就可以得到一组a0和b0
 * 
 * 有通解b = b0 - k * (n / gcd(n, d)) 这里加减都无妨
 * min b = b0 % (n / gcd(n, d))
 **/
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> d >> x >> y;
        int gcd = exgcd(n, d, a, b);
        if ((y - x) % gcd)
            puts("Impossible");
        else {
            b *= (y - x) / gcd;
            n /= gcd;
            cout << (b % n + n) % n << endl;
        }
    }
}