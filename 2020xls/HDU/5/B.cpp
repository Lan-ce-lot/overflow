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
const int mod = 998244353;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0,f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
ll t, n;
ll qpow(ll x, ll n, ll p) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % p;
        }
        x = x * x % p;
        n >>= 1;
    }
    return res;
}

ll tem[maxn];
ll rev(ll a) {
    return qpow(a, mod - 2, mod);
}
void solve()
{
    t = read();
    while (t--) {
        n = read();
        ll tem = 2 * qpow(3, n, mod) % mod;
        tem = tem * rev(qpow(2, n, mod)) % mod;
        tem = (tem + 1 + qpow(2, n, mod)) % mod;
        printf("%lld\n", tem);
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}