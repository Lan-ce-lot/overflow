/*************************************************************************
 > FileName:
 > Author:      Lance
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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
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

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }
    return d;
}
ll a, b, c, x, y;

int main()
{
    ll m, n, gcd, L;
    while (~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L))
    {
        a = m - n;
        b = L;
        c = y - x;
        if (a < 0)
        {
            a = -a;
            c = -c;
        }
        gcd = extgcd(a, b, x, y);
        if (c % gcd != 0)
            puts("Impossible");
        else
        {
            x = x * c / gcd;
            int t = b / gcd;
            x = (x % t + t) % t;
            printf("%lld\n", x);
        }
    }
    return 0;
}

