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
const int maxn = 1e5 + 5;
ll maxd;
ll a[maxn];
struct node
{
    ll sum;
    ll lazy;
    ll dep;
} A[maxn << 2];

void build(int u, int l, int r, ll d)
{
    if (l == r)
    {
        A[u].sum = a[l];//这里可以改为初始数组的
        A[l].dep = d;
        maxd = max(maxd, d);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * u, l, mid, d + 1);
    build(2 * u + 1, mid + 1, r, d + 1);
    A[u].sum = A[2 * u].sum + A[2 * u + 1].sum;//等价pushup操作
}


ll query(int u, int l ,int r, ll t, ll tt)
{
    if (l == r)
        return (1 << t) * (tt + A[u].sum);
    int mid = (l + r) / 2;
    return query(u * 2, l, mid, t - 1, tt + A[u].sum) + query(u * 2 + 1, mid + 1, r, t - 1, tt + A[u].sum);
}






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
ll n, m, qwq, s[maxn];
int main()
{
    n = read(), m = read(),qwq = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    build(1, 1, n, 1);
    ll ans = query(1, 1, n, maxd - 1, 0), y = 1 << (maxd - 1);
    ll yue = __gcd(y, qwq);
    y /= yue;
    qwq /= yue;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + (((1 << A[i].dep) - 1) << (maxd - A[i].dep));
    }
    while (m--)
    {
        ll l = read(), r = read(), w = read();
        ans += (s[r] - s[l - 1]) * w;
        printf("%lld\n", ans / y * qwq);
    }
    return 0;
}

