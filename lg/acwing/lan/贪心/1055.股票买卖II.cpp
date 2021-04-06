#include <bits/stdc++.h>

using namespace std;
int n, a[100005], f[100005][2];
int main() {
    cin >> n;
    memset(f,0xcf,sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {          
        f[i][0] = max(f[i - 1][1] + a[i], f[i - 1][0]);  // 卖或 不买 当前(i)没有股票
        f[i][1] = max(f[i - 1][0] - a[i], f[i - 1][1]);  // 买或 不卖 当前(i)拥有股票
    }
    cout << max(f[n][0], f[n][1]) << endl;
}
