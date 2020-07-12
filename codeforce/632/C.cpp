/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

int t, n;
ll a[maxn], ans = 0, sum[maxn];
map<ll, ll> M;
void solve()
{
    cin >> n;
//    M[0] = 1;
    ll tem = 0;
    M[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        if (M[sum[i]] || (sum[i] == 0 && M[sum[i]] == 0)) {
            tem = max(tem, M[sum[i]] + 1);
        }

        ans += i - tem;//debug(ans);
        M[sum[i]] = i;
    }
    cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

