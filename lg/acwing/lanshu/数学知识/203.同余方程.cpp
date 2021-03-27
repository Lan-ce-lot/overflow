#include <bits/stdc++.h>

using namespace std;
int a, b;
int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
/**
 * a * x = 1 + y * b
 * a * x - y * b = 1
 */
int main() {
    cin >> a >> b;
    int x, y, d = exgcd(a, b, x, y);
    cout << (x % (b / d) + (b / d)) % (b / d) << endl;
}
