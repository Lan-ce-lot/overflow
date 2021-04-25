#include <bits/stdc++.h>

using namespace std;
int n;
const int maxn = 1e4 + 5;
int in[maxn], po[maxn];
struct node {
    int v;
    node *l, *r;
};
node *build(int pl, int pr, int il, int ir) {
    if (pl > pr) return NULL;
    node *root = new node;
    int k = il;
    while (in[k] != po[pl]) k++;
    root->v = in[k];
    root->l = build(pl + 1, pl + 1 + k - 1 - il, il, k - 1);
    root->r = build(pr - ir + k + 1, pr, k + 1, ir);
    return root;
}
int f = 0;
void bfs(node *root) {
    queue<node *> Q;
    Q.push(root);
    while (Q.size()) {
        node *top = Q.front();
        Q.pop();
        if (f !=0) {
            cout << ' ' << top->v;
        } else {
            cout << top->v;
        }
        f++;
        if (top->r != NULL) Q.push(top->r);
        if (top->l != NULL) Q.push(top->l);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in[i];
    for (int i = 1; i <= n; i++) cin >> po[i];
    node *root = build(1, n, 1, n);
    bfs(root);
    puts("");
    return 0;
}
