#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 3e5 + 5;
const int N = 1e3 + 5;
const int INF = 0x3f3f3f;
int n, m;
int vis[maxn];
int dis[maxn];
int h[maxn], tot;
struct node {
    int to, v, ne;
}G[maxn];
void add(int a, int b, int c) {
    G[tot] = {b, c, h[a]}, h[a] = tot++;  
}
int dj() {
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<PII, vector<PII>, greater<PII> > H;
    H.push({0, 1});
    dis[1] = 0;
    while (H.size()) {
        PII top = H.top();
        H.pop();
        int v = top.second, d = top.first;
        if (vis[v]) continue;
        vis[v] = 1;
        for (int i = h[v]; ~i; i = G[i].ne) {
            int j = G[i].to;
            if (dis[j] > dis[v] + G[i].v) {
                dis[j] = dis[v] + G[i].v;
                H.push({dis[j], j});
            }
        }
    }
    if (dis[n] != 0x3f3f3f3f) return dis[n];
    return -1;
}


int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(G, 0x3f, sizeof G);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dj() << endl;
    return 0;
}