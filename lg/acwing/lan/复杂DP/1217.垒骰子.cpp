#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, mod = 1e9 + 7;

struct mat {
    ll a[6][6];
};
int get(int x) { return x - x < 3 ? 3 : - 3; }
mat mul(mat A, mat B) {
    mat res{{0}};
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                res.a[i][j] = (res.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
    return res;
}
mat qpow(mat A, int n) {
    mat res{{4, 4, 4, 4, 4, 4}};
    while (n) {
        if (n & 1) res = mul(res, A);
        A = mul(A, A);
        n >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> m;
    mat A;
    fill(A.a[0], A.a[0] + 6 * 6, 4);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        A.a[x][get(y)] = 0;
        A.a[y][get(x)] = 0;
    }
    A = qpow(A, n - 1);
    int res = 0;
    for (int i = 0; i < 6; i++) res = (res + A.a[0][i]) % mod;
    cout << res << endl;
}