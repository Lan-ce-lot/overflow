#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[3][99];
void H(ll a[], ll b[], ll c[]) {
    ll mid = (1ll << (n - 1));
    if (n == 0) return;
    if (m >= mid)
        c[++c[0]] = n--, m -= mid, H(b, a, c);
    else
        a[++a[0]] = n--, H(a, c, b);
}

void Print() {
    ll i, j;
    for (i = 0; i < 3; i++) {
        for (j = 1; j <= a[i][0]; j++)
            cout << a[i][j] << '-';
        if (i != 2)
            cout << "0-";
    }
}

int main() {
    while (cin >> n >> m, m) {
    	memset(a, 0, sizeof a);
        H(a[0], a[1], a[2]);
        Print();
        puts("");
    }
}
