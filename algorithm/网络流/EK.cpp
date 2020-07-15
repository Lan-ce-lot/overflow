#include<bits/stdc++.h>

typedef long long ll;

using namespace std;
const int maxn = 5e4 + 5;
const int INF = 0x3f3f3f3f;

int tot = 1, flag[2510][2510];
int n, m, s, t, u, v;
ll ans, w;

vector<Edge> edges;
vector<int> G[maxn];
ll a[maxn]; // dis
int p[maxn];

struct Edge {
    int from, to;
    ll cap, flow;
    Edge(int u, int v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
};

void AddEdge(int from, int to, ll cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, cap, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}




struct EdmondsKarp {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    ll a[maxn]; // dis
    int p[maxn];

    void init(int n) {
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, cap, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    ll Maxflow(int s, int t) {
        ll flow = 0;
        for (;;) {
            memset(a, 0, sizeof a);
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while (!Q.empty()) {
                int x = Q.front();
                Q.pop();
                for (int i = 0; i < G[x].size(); i++) {
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow) {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x] * 1ll, e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};


signed main() {
//	cout << 1 << endl; 
    scanf("%d%d%d%d", &n, &m, &s, &t);
    EdmondsKarp E;
    E.n = n;
    E.m = m;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%lld", &u, &v, &w);
        if (flag[u][v] == 0) {
            E.AddEdge(u, v, w);
            flag[u][v] = tot;
        } else {
            E.edges[flag[u][v] - 1].flow += w;
        }
    }
    ans = E.Maxflow(s, t);
    printf("%lld", ans);
    return 0;
}