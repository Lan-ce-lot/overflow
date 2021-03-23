#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll n, A[3][N], INF = 0x3f3f3f3f, cnt[N], s[N], cs[N], as[N];
int main() {
    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j], A[i][j]++;
    for (int i = 0; i < n; i++) cnt[A[0][i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) as[i] = s[A[1][i] - 1];

    memset(cnt, 0 ,sizeof cnt);
    memset(s, 0, sizeof s);
    
    ll ans = 0;
    for (int i = 0; i < n; i++) cnt[A[2][i]]++;
    for (int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for (int i = 0; i < n; i++) cs[i] = s[N - 1] - s[A[1][i]];

    for (int i = 0; i < n; i++) ans += as[i] * cs[i];
    cout << ans << endl;
}