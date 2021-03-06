#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#define sd(n) scanf("%d", &n)
#define sdd(n, m) scanf("%d%d", &n, &m)
#define sddd(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define pd(n) printf("%d\n", n)
#define pc(n) printf("%c", n)
#define pdd(n, m) printf("%d %d", n, m)
#define pld(n) printf("%lld\n", n)
#define pldd(n, m) printf("%lld %lld\n", n, m)
#define sld(n) scanf("%lld", &n)
#define sldd(n, m) scanf("%lld%lld", &n, &m)
#define slddd(n, m, k) scanf("%lld%lld%lld", &n, &m, &k)
#define sf(n) scanf("%lf", &n)
#define sc(n) scanf("%c", &n)
#define sff(n, m) scanf("%lf%lf", &n, &m)
#define sfff(n, m, k) scanf("%lf%lf%lf", &n, &m, &k)
#define ss(str) scanf("%s", str)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define mem(a, n) memset(a, n, sizeof(a))
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mod(x) ((x) % MOD)
#define gcd(a, b) __gcd(a, b)
#define lowbit(x) (x & -x)
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
inline int read()
{
    int ret = 0, sgn = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * sgn;
}
inline void Out(int a) //ê?3?ía1ò
{
    if (a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
///快速幂m^k%mod
ll qpow(int m, int k, int mod)
{
    ll res = 1, t = m;
    while (k)
    {
        if (k & 1)
            res = res * t % mod;
        t = t * t % mod;
        k >>= 1;
    }
    return res;
}

// 快速幂求逆元
int Fermat(int a, int p) //费马求a关于b的逆元
{
    return qpow(a, p - 2, p);
}

///扩展欧几里得
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll ans = exgcd(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - a / b * y;
    return ans;
}

///使用ecgcd求a的逆元x
ll mod_reverse(ll a, ll p)
{
    ll d, x, y;
    d = exgcd(a, p, x, y);
    if (d == 1)
        return (x % p + p) % p;
    else
        return -1;
}

///中国剩余定理模板

ll china(ll a[], ll b[], ll n)
{
    ll a1 = a[1], b1 = b[1];
    bool flag = 1;
    for (int i = 2; i <= n; i++)
    {
        ll A = a1, B = a[i], C = b[i] - b1;
        ll x, y;
        ll gcd = exgcd(A, B, x, y);
        if (C % gcd)
        {
            flag = 0;
            break;
        }
        x = ((x * C / gcd) % (B / gcd) + (B / gcd)) % (B / gcd);
        b1 = a1 * x + b1;
        a1 = a1 / gcd * a[i];
    }
    if (b1)
        return b1;
    else
        return a1;
}

int t;
ll a, n, m, k;
int main()
{
    sd(t);
    while (t--)
    {
        sldd(a, m);
        sldd(n, k);
        ll res = gcd(n, m);
        ll ans = (qpow(a, gcd(m, n), k) + k - 1) % k;
        pld(ans);
    }
    return 0;
}


