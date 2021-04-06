#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int t[N], n, x, y, level[N];
int lowbit(int x) { return x & -x; }
void add(int u, int v) {
    for (; u < N; u += lowbit(u)) t[u] += v;
}

int ask(int u) {
    int res = 0;
    for (; u; u -= lowbit(u)) res += t[u];
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &x, &y), level[ask(++x)]++, add(x, 1);
    for (int i = 0; i < n; i++) cout << level[i] << endl;
}
