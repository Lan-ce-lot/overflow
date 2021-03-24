#include <bits/stdc++.h>



using namespace std;
const int N = (1 << 20) + 10;
#define ll long long
ll primes[N], minp[N], cnt, n;
bool st[N];
void get_p(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i, minp[i] = i;
        for (int j = 0; i * primes[j] <= n; j++) {
            st[primes[j] * i] = 1, minp[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}


int main() {
    get_p(N - 1);
    int fac[30], sum[N];
    while (cin >> n) {
        int tot = 0, k = 0;
        while (n > 1) {
            int p = minp[n];
            fac[k] = p, sum[k] = 0;
            while (n % p == 0) {
                n /= p;
                sum[k]++;
                tot++;
            }
            k++;
        }

        ll res = 1;
        for (int i = 1; i <= tot; i++) res *= i;
        for (int i = 0; i < k; i++)
            for (int j = 1; j <= sum[i]; j++) res /= j;
        printf("%d %lld\n", tot, res);
    }
}