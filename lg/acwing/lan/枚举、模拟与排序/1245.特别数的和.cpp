#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans, n;
set<int> S{2, 0, 1, 9};
bool check(int n) {
    while (n) {
        if (S.count(n % 10)) return 1;
            n /= 10;
    }
    return 0;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans += check(i) ? i : 0;
    }
    cout << ans << endl;
}