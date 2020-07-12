/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 500005;

ll q_pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

ll t, n, q, pre[maxn], s, x, a, l, r;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        memset(pre, 0, sizeof(pre));
        scanf("%lld%lld", &n, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld%lld", &r, &s, &x, &a);
            pre[i + 1] = ((pre[i] + a - pre[x] + mod) % mod * s % mod * q_pow(r, mod - 2) % mod + pre[x] % mod) % mod;
//            ll p=r*q_pow(s,MOD-2)%MOD;
//            pre[i+1]=(pre[i]+a*s%MOD*q_pow(r,MOD-2)%MOD+((pre[i]-pre[x]+MOD)%MOD)*((1-p+MOD)%MOD)%MOD*s%MOD*q_pow(r,MOD-2)%MOD)%MOD;

        }
        for (int i = 1; i <= q; i++)
        {
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", (pre[r] - pre[l] + mod) % mod);
        }
    }
    return 0;
}
