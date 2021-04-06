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
/**
 * 暴力搜索可行的号码牌
 * @param {
 *     "last": u表示上一个枚举的质数是谁,比如质数为P = 2,3,5,7....: int,
 *     "prod": 答案,约数和==输入的人的号码牌: int,
 *     "s": s参数就代表着从一开始的S除以(1+pk+pk^2+…+pk^ak)后剩余的乘积: int,
 * }
 * @return if create s == 1 then return void
 */
void dfs(int last, int prod, int s) {
    if (s == 1) { // 已经凑出来了
        ans[len++] = prod;
        return;
    }
    if (s - 1 > (last < 0 ? 1 : prime[last]) && is_p(s - 1))
        ans[len++] = prod * (s - 1);
    for (int i = last + 1; prime[i] <= s / prime[i]; i++) {
        int p = prime[i];
        for (int j = 1 + p, t = p; j <= s; t *= p, j += t)// t，p最大次幂, j所有数的和
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