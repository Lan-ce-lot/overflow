#include <cstdio>
#include <queue>
#include <algorithm>

const int N_MAX = 3000000 + 7;
const int M_MAX = 5000000 + 7;

struct Edge
{
    int start, to, w, next;
    double k;
} edge[M_MAX], edge2[M_MAX];

int edge_size, head[N_MAX];

void add_edge(int u, int v, int w, double k)
{
    edge[++edge_size] = (Edge) {u, v, w, head[u], k};
    head[u] = edge_size;
}

int head2[N_MAX], edge_size2;

void add_edge2(int u, int v, int w)
{
    edge2[++edge_size2] = (Edge) {u, v, w, head2[u], 0};
    head2[u] = edge_size2;
}

int low[N_MAX], dfn[N_MAX], stack[N_MAX], top;
bool instack[N_MAX];
int scc[N_MAX], sc, index;

void tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    stack[++top] = u;
    instack[u] = true;
    for (int e = head[u]; e; e = edge[e].next)
    {
        int v = edge[e].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        }
        else if (instack[v])
        {
            low[u] = std::min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++sc;
        while(stack[top] != u)
        {
            scc[stack[top]] = sc;
            instack[stack[top]] = false;
            top--;
        }
        scc[u] = sc;
        instack[u] = false;
        top--;
    }
}

int f[N_MAX], val[N_MAX], in[N_MAX], ans;
std::queue <int> q;
int s;

void topo()
{
    for (int i = 1; i <= sc; i++)
    {
        if (!in[i])
            q.push(i);
        f[i] = -0x7fffffff;
    }
    f[scc[s]] = val[scc[s]];
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int e = head2[u]; e; e = edge2[e].next)
        {
            int v = edge2[e].to;
            f[v] = std::max(f[u] + edge2[e].w + val[v], f[v]);
            in[v]--;
            if (!in[v])
                q.push(v);
        }
    }
    for (int i = 1; i <= sc; i++)
        ans = std::max(ans, f[i]);
}

int n, m, u, v, w;
double k;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %lf", &u, &v, &w, &k);
        add_edge(u, v, w, k);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        if (scc[edge[i].start] != scc[edge[i].to])
        {
            add_edge2(scc[edge[i].start], scc[edge[i].to], edge[i].w);
            in[scc[edge[i].to]]++;
        }
        else
        {
            while (edge[i].w)
            {
                val[scc[edge[i].to]] += edge[i].w;
                edge[i].w *= edge[i].k;
            }
        }
    }
    scanf("%d", &s);
    topo();
    printf("%d\n", ans);
}

