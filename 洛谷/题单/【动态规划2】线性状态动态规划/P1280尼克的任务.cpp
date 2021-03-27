#include <bits/stdc++.h>

using namespace std;
int n, m, k, f[10005], sum[10005], num = 1;
struct node {
    int s, e;
} a[10005];
bool cmp(node x, node y) { return x.s > y.s; }
int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i].s >> a[i].e;
        sum[a[i].s]++;
    }

    sort(a + 1, a + k + 1, cmp);
    for (int i = n; i >= 1; i--) {
        if (!sum[i]) {
            f[i] = f[i + 1] + 1;
        } else {
            for (int j = 1; j <= sum[i]; j++) {
                if (f[i + a[num].e] > f[i]) f[i] = f[i + a[num].e];
                num++;
            }
        }
    }
    cout << f[1] << endl;
}
