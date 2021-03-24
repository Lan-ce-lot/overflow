#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 2010;
PII g[N];
int cnt[N], ans, Left, Right;
signed main()
{
    int n, L;
    cin >> L >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].x >> g[i].y;
        ans = max(ans, g[i].y == 0 ? g[i].x : (L - g[i].x));
        Left = max(Left, g[i].y == 0 ? g[i].x : Left);
        Right = max(Right, g[i].y == 1 ? (L - g[i].x) : Right);
        cnt[g[i].y]++;
    }
    cout << cnt[0] - (Right < Left) << ' ' << ans;
    return 0;
}