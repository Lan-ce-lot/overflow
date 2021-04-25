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
    while (q.size()) {
        u = q.front(), q.pop();
        for (auto i : g[u])
            if (f[i] += f[u] % M, !--I[i])
                if (q.push(i), !O[i]) S += f[i] % M;
    }
    cout << S % M;
}
