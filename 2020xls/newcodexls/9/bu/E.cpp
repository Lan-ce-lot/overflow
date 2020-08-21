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
typedef __int128 LL; 
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 998244353;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 5000005;
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

ll  top;

ll p[maxn], ans = 1;
ll num_x[maxn], num_y[maxn];
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) %mod;
        b >>= 1;
    }
    return res;
}


void solve()
{
    ll a = read(),b = read(),c = read(),d = read(),x = read(),y = read();
    
    ll xx = x, yy = y, e = d - c + 1;
    for (int i = 2; i <= xx / i; i++) {
        if (xx % i == 0 && yy % i == 0) {
            p[top] = i;
            num_x[top] = num_y[top] = 0;
            while (xx % i == 0) {
                num_x[top]++;
                xx /= i;
            }
            while (yy % i == 0) {
                num_y[top]++;
                yy /= i;
            }
            top++;
        }
        while (xx % i == 0) xx /= i;
        while (yy % i == 0) yy /= i;
    }
    
    if (xx != 1 && yy != 1 && max(xx, yy) % min(xx, yy) == 0) {
        ll i = min(xx, yy);
        p[top] = i;
        while (xx % i == 0) {
            num_x[top]++;
            xx /= i;
        }
        while (yy % i == 0) {
            num_y[top]++;
            yy /= i;
        }
        top++;
    }
    ans = 1;
    for (ll i = 0; i < top; i++) {
        ll z = 0;
        ll temx, temy;
//		cout << p[i] << ' ' << num_x[i] << ' ' << num_y[i] << endl;
        for (ll j = a; j <= b; j++) {
            temx = (num_x[i] * j) % mod;
            temy = (num_y[i] * c) % mod;
            if (temx <= temy) z += temx * e;
            else if (temx >= (num_y[i] * d)) z += (num_y[i] * c + num_y[i] * d) * e / 2;
            else {
                ll r = temx / num_y[i];
                z += (d - r) * temx;
                z += (temy + r * num_y[i]) * (r - c + 1) / 2;
            }
            z %= mod - 1;
        }
        ans = (ans * qpow(p[i], z)) % mod;
    }
    
    printf("%lld\n", ans);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

