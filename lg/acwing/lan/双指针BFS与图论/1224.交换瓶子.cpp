#include <bits/stdc++.h>

using namespace std;
int n, a[10005],vis[10005], ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            ans++;
            for (int j = i; !vis[j]; j=a[j])
                vis[j] = 1;
        }
    cout << n - ans << endl;
    
}