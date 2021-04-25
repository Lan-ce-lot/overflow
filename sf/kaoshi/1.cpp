#include <bits/stdc++.h>
using namespace std;
const int M = 8009999, N = M;
vector<int> g[N];
int n, m, I[N], O[N], S, f[N], i, a, u;
queue<int> q;
int main() {
    cin >> n >> m;
    for (; i < m; i++) cin >> a >> u, g[a].push_back(u), I[u]++, O[a]++;
    for (i = 1; i <= n; i++)
        if (!I[i]) f[i] = 1, q.push(i);
    while (!q.empty()) {
        u = q.front(), q.pop();
        for (i = 0; i < g[u].size(); i++) {
            f[g[u][i]] += f[u] % M, I[g[u][i]]--;
            if (!I[g[u][i]]) {
                q.push(g[u][i]);
                if (!O[g[u][i]]) S += f[g[u][i]] % M;
            }
        }
    }
    cout << S % M;
}
