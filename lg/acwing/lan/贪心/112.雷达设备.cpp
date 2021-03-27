#include <bits/stdc++.h>

using namespace std;
int flag, ans;
double n, m, r = -0x3f3f3f3f;
struct node {
    double x, y;
    bool operator<(node &W) { return x != W.x ? y < W.y : x < W.x; }
} A[1005];

node get(node a) {
    if (a.y > m) flag = 1;
    return {a.x - sqrt(m * m - a.y * a.y), a.x + sqrt(m * m - a.y * a.y)};
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> A[i].x >> A[i].y, A[i] = get(A[i]);
    if (flag) {
        puts("-1");
        return 0;
    }
    sort(A + 1, A + int(n) + 1);
    for (int i = 1; i <= n; i++)
        if (A[i].x > r) ans++, r = A[i].y;
    cout << ans << endl;
}
