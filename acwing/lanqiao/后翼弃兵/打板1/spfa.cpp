#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, dis[maxn], vis[maxn];
struct node {
    int to, v, ne;
}G[maxn];
int h[maxn], tot;
void add(int a, int b, int c) {
    G[tot] = {b, c, h[a]}, h[a] = tot++;
}
int spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;
    while (Q.size()) {
        int top = Q.front();
        Q.pop();
        vis[top] = 0;
        for (int i = h[top]; ~i; i = G[i].ne) {
            int j = G[i].to;
            if (dis[j] > dis[top] + G[i].v) {
                dis[j] = dis[top] + G[i].v;
                if (!vis[j])
                    Q.push(j), vis[j] = 1;
            }
        }
    }
    if (dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}


int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int f = spfa();
    if (f == -1) {
        puts("impossible");
    } else 
        cout << f << endl;
    return 0;
}