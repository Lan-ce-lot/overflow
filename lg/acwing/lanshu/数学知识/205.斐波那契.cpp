#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int mod = 1e4;
ll n;
struct mat {
    int a[2][2];
};

ll mul(int a, int b) {
    ll res = 0;
    while (b) {
        if (b & 1) res += a, res %= mod;
        a <<= 1;
        a %= mod;
        b >>= 1;
    }
    return res;
}

mat mul_mat(mat A, mat B) {
    mat C;
    C.a[0][0] = C.a[0][1] = C.a[1][0] = C.a[1][1] = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C.a[i][j] =
                    (C.a[i][j] % mod + mul(A.a[i][k], B.a[k][j]) % mod) % mod;
            }
        }
    }
    return C;
}

mat pow_mat(mat A, int n) {
    mat res;
    res.a[0][0] = 1, res.a[0][1] = 0, res.a[1][0] = 0, res.a[1][1] = 1;
    while (n) {
        if (n & 1) res = mul_mat(res, A);
        A = mul_mat(A, A);
        n >>= 1;
    }
    return res;
}

int f(int n) {
    mat A, B;
    A.a[0][0] = 0, A.a[1][1] = A.a[0][1] = A.a[1][0] = 1;
    A = pow_mat(A, n + 1);
    return (A.a[0][0]) % mod;
}

int main() {
    while (cin >> n, ~n) cout << f(n) << endl;
}