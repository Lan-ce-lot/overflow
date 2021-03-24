#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
#define ll long long
ll primes[N], minp[N], cnt, n, len, ans[N];
bool st[N];
void get_p(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; i * primes[j] <= n; j++) {
            st[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}
bool is_p(int x) {
    if ()
}
void dfs(int last, int pro, int s) {
    if (s == 1) {
        ans[len++] = pro;
        return;
    }
    if (s - 1 > (last < 0 ? 1 : primes[last]) && is_p(s - 1)) {
        ans[len++] = pro * (s - 1);
    }
}

int main() {
    get_p(N - 1);

    while (cin >> n) {
    }
}