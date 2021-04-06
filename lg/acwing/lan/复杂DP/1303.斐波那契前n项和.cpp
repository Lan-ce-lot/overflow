#include <bits/stdc++.h>
// 矩阵快速幂
using namespace std;
typedef long long ll;
ll n, m;
struct mat {
    ll a[2][2];
};
ll mul(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) res += a, res %= m;
        a <<= 1, a %= m;
        b >>= 1;
    }
    return res;
}

mat mul_mat(mat A, mat B) {
    mat res;
    memset(res.a, 0, sizeof res.a);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res.a[i][j] =
                    (res.a[i][j] % m + mul(A.a[i][k], B.a[k][j]) % m) % m;
    return res;
}

mat pow_mat(mat A, ll n) {
    mat res;
    res.a[0][0] = 1, res.a[0][1] = 0, res.a[1][0] = 0, res.a[1][1] = 1;
    while (n) {
        if (n & 1) res = mul_mat(res, A);
        A = mul_mat(A, A);
        n >>= 1;
    }
    return res;
}

ll quick_fib(ll n) {
    mat res;
    res.a[0][0] = 1, res.a[0][1] = 1, res.a[1][0] = 1, res.a[1][1] = 0;
    res = pow_mat(res, n);
    return res.a[0][1];
}

int main() {
    cin >> n >> m;
    cout << quick_fib(n + 2) % m - 1 << endl;
}