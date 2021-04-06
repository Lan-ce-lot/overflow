#include <iostream>
using namespace std;
#define ll long long
ll n, a[100005], e, s, i, l, c, d = 1, r;
int main() {
    cin >> n;
    while (i < n) cin >> a[i++];
    while (l < n) {
        r = l + (1 << c++);
        while (l < min(r, n)) s += a[l++];
        if (e < s) d = c, e = s;
        l = r, s = 0;
    }
    cout << d << endl;
}