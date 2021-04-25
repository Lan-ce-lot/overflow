#include <bits/stdc++.h>

using namespace std;
int n, m, k;
const int maxn = 1e3 + 5;
int p[maxn];

int find(int x) {
    if (x == p[x]) return p[x];
    else return p[x] = find(p[x]);
}

void Union(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
        p[x] = y;
    }
}
int G[105][105];
int main() {
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, r;
        cin >> a >> b >> r;
        if (r == 1) {
            Union(a, b);
        }
        G[a][b] = G[b][a] = r;
    }

    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            if (G[a][b] == -1) {
                puts("OK but...");
            } else {
                puts("No problem");
            }
        } else {
            if (G[a][b] == 0) {
                puts("OK");
            } else if (G[a][b] == -1) {
                puts("No way");
            }
        }
    }


    return 0;
}
