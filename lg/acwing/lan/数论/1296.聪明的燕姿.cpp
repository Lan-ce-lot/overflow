#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int prime[N], cnt, ans[N], len, n;
bool st[N];
void get_p(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; prime[j] * i <= n; j++) {
            st[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
bool is_p(int x) {
    if (x < N) return !st[x];
    for (int i = 0; prime[i] <= x / prime[i]; i++)
        if (x % prime[i] == 0) return 0;
    return 1;
}
void dfs(int last, int prod, int s) {
    if (s == 1) {
        ans[len++] = prod;
        return;
    }
    if (s - 1 > (last < 0 ? 1 : prime[last]) && is_p(s - 1))
        ans[len++] = prod * (s - 1);
    for (int i = last + 1; prime[i] <= s / prime[i]; i++) {
        int p = prime[i];
        for (int j = 1 + p, t = p; j <= s; t *= p, j += t)
            if (s % j == 0) dfs(i, prod * t, s / j);
    }
}

int main() {
    get_p(N - 1);
    int s;
    while (cin >> s) {
        len = 0;
        dfs(-1, 1, s);
        cout << len << endl;
        if (len) {
            sort(ans, ans + len);
            for (int i = 0; i < len; i++) cout << ans[i] << ' ';
            puts("");
        }
    }
}