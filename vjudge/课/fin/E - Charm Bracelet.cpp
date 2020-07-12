#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

int t, n, m;
int a[maxn];
struct node{
    int l, r;
}N[15005];
int dp[15005];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> N[i].l >> N[i].r;

    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= N[i].l; j--) {
            dp[j] = max(dp[j], dp[j - N[i].l] + N[i].r);
        }
    }
    cout << dp[m] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

