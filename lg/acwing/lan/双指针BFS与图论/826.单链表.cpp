#include <bits/stdc++.h>


using namespace std;
int n, a, b;
char c;
struct node {
    int ne, v;
}G[100005];
int h = -1, tot;
void add_head(int x) {
    G[tot] = {h, x}, h = tot ++;
}
void add_k(int u, int x) {
    G[tot] = {G[u].ne, x}, G[u].ne = tot++;
}

void remove(int u) {
    G[u].ne = G[G[u].ne].ne;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'H') {
            cin >> a;
            add_head(a);
        } else if (c == 'I') {
            cin >> a >> b;
            add_k(a - 1, b);
        } else {
            cin >> a; 
            if (!a) h = G[h].ne;
            else remove(a - 1);
        }
    }
    for (int i = h; ~i; i = G[i].ne) cout << G[i].v << ' ';
    puts("");
}