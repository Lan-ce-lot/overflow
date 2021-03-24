#include <algorithm>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
typedef pair<ll, ll> PII;
const ll N = 2010;
PII g[N];
int cnt[N], ans, Left, Right;
int main()
{
    int n, L;
    cin >> L >> n;
    for (int i = 0; i < n; i++) {
        cin >> g[i].first >> g[i].second;
        ans = max(ans * 1ll, g[i].second == 0 ? g[i].first : (L - g[i].first));
        Left = max(Left * 1ll, g[i].second == 0 ? g[i].first : Left);
        Right = max(Right * 1ll, g[i].second == 1 ? (L - g[i].first) : Right);
        cnt[g[i].second]++;
    }
    cout << cnt[0] - (Right < Left) << ' ' << ans;
    return 0;
}