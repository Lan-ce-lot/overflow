#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = (1 << 20) + 10;
ll x;
/* 多重集合的排列数问题

*/

/*
筛掉的一定是合数，且一定用他最小质因子筛的
p_j一定小于等于i的最小质因子<-   i % primes[j] == 0

这句话只会执行一次st[primes[j] * i] = 1;所以是O(n)
*/

ll primes[N], cnt, minp[N];
bool st[N];
void get_prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i, minp[i] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = 1;
            minp[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    get_prime(N - 1);
    int fac[30], sum[N];// 因子和因子个数
    while (cin >> x) {
        int k = 0, tot = 0;// 索引和总数
        while (x > 1) {
            int p = minp[x];
            fac[k] = p, sum[k] = 0;
            while (x % p == 0) {
                x /= p;
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