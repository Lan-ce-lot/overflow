#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[1005];
vector<int> ans;
void dfs(int u, int all) {
    if (u == all + 1) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = u; i <= n; i++) {
        if (!vis[i]) {
            ans.push_back(i);
            vis[i] = 1;
            dfs(i + 1, all);
            vis[i] = 0;
            ans.pop_back();
        }
    }
}

int main() {
    cout << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dfs(1, i);
    }
}