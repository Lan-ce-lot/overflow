#include <bits/stdc++.h>
using namespace std;
int n, d, k;
struct node {
    int t, z;
    bool operator < (node W) {
        if (z != W.z) return z < W.z;
        return t < W.t;
    }
}N[100005];
set<int> ans;
int num[100005];
int main() {
    cin >> n >> d >> k;
    for (int i = 1; i <= n; i++)
        cin >> N[i].t >> N[i].z, ans.insert(N[i].z);
    sort(N + 1, N + n + 1);
    int l = 1, r = 1 + d;
    int now = N[1].z;
    num[now] = 1;
    for (int i = 2; i <= n; i++) {
        if (N[i].z == now) {
            while (N[l].t + d <= N[i].t && l++ < i);
            num[now] = max(num[now], i - l + 1);
        } else {
            l = i;
            num[now = N[i].z] = 1;
        }
    } 
    for (auto it : ans) 
        if (num[it] >= k) cout << it << endl;

}