#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e6 + 5;
int dis[N], vis[N], n, m;

int p[N];
int find(int x) {
    if (x != p[x]) return p[x] = find(p[x]);
    return p[x];
}
struct node {
    int a, b, v;
    bool operator < (node &W) {
        return v < W.v;
    }
}E[N];
void Union(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) p[a] = b;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i <= m; i++) p[i] = i; 
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[i] = {a, b, c};
    }
    sort(E, E + m);
    int ans = 0, all = 0;
    for (int i = 0; i < m; i++) {

        if (find(E[i].a) != find(E[i].b)) {
            Union(E[i].a, E[i].b);
            ans += E[i].v;
            all++;
        }
		if (all >= n - 1)
        {
            cout << ans << endl;
            return 0;
        }
    }
    puts("impossible");
    return 0;
}
