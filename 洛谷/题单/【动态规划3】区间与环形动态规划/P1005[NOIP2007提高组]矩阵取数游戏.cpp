#include <bits/stdc++.h>
#define bll __int128
using namespace std;
int n, m, M[1005];
bll f[1005][1005], ans, p[1995];
inline int read() {
    int X = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
    return X * w;
}

void print(bll x) {
    if (!x) return;
    if (x) print(x / 10);
    putchar(x % 10 + '0');
}

bll dfs(int l, int r, bll d) {
    if (~f[l][r]) return f[l][r];
    if (r - l >= 1)
        f[l][r] = max(M[l] * p[d] + dfs(l + 1, r, d + 1),
                      M[r] * p[d] + dfs(l, r - 1, d + 1));
    else
        f[l][r] = M[l] * p[d];
    return f[l][r];
}

int main() {
    n = read(), m = read();
    p[0] = 1;
    for (int i = 1; i <= m; i++) p[i] = p[i - 1] * 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) M[j] = read();
        memset(f, -1, sizeof f);
        ans += dfs(1, m, 1);
    }
    if (!ans)
        printf("0");
    else
        print(ans);
}