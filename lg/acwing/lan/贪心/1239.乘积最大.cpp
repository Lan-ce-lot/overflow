#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll n, k, a[N], f[N], a_l, f_l;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        if (c >= 0) {
            a[++a_l] = c;
        } else {
            f[++f_l] = c;
        }
    }
    int i_a = 1, i_b = 1;
    sort(a + 1, a + a_l + 1);
    sort(f + 1, f + f_l + 1);
    int to = 0;
    while (++to <= k) {
        
        if (a[i_a] * a[i_b]) {

        }
    }
}
