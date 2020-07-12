/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <bitset>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1e5 + 5;

int t, n, m, q;

struct node
{
    ll sum;
    int _max, _min, add;
} A[maxn << 2];

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

void build()
{
    for (m = 1; m <= n; m <<= 1);
    for (int i = m + 1; i <= m + n; i++)
        A[i].sum = A[i]._min = A[i]._max = read();
    for (int i = m - 1; i; i--)
    {
        A[i].sum = A[i << 1].sum + A[i << 1 | 1].sum;
        A[i]._min = min(A[i << 1]._min, A[i << 1 | 1]._min);
        A[i << 1]._min -= A[i]._min, A[i << 1 | 1]._min -= A[i]._min;
        A[i]._max = max(A[i << 1]._max, A[i << 1 | 1]._max);
        A[i << 1]._max -= A[i]._max, A[i << 1 | 1]._max -= A[i]._max;
    }
}
//单点更新
void update_node(int x, int v, int a = 0)
{
    x += m, A[x]._max += v, A[x]._min += v, A[x].sum += v;
    for (; x > 1; x >>= 1)
    {
        A[x].sum += v;
        a = min(A[x]._min, A[x ^ 1]._min);
        A[x]._min -= a, A[x ^ 1]._min -= a, A[x >> 1]._min += a;
        a = max(A[x]._max, A[x ^ 1]._max);
        A[x]._max -= a, A[x ^ 1]._max -= a, A[x >> 1]._max += a;
    }
}
//区间更新
void update_part(int s, int t, int v)
{
    int a = 0, lc = 0, rc = 0, len = 1;
    for (s += m - 1, t += m + 1; s ^ t ^ 1; s >>= 1, t >>= 1, len <<= 1)
    {
        if (s & 1 ^  1)
            A[s ^ 1].add += v, lc += len, A[s ^ 1]._min += v, A[s ^ 1]._max += v;
        if (t & 1)
            A[t ^ 1].add += v, rc += len, A[t ^ 1]._min += v, A[t ^ 1]._max += v;
        A[s >> 1].sum += v * lc, A[t >> 1].sum += v * rc;
        a = min(A[s]._min, A[s ^ 1]._min), A[s]._min -= a, A[s ^ 1]._min -= a, A[s >> 1]._min += a;
        a = min(A[t]._min, A[t ^ 1]._min), A[t]._min -= a, A[t ^ 1]._min -= a, A[t >> 1]._min += a;
        a = max(A[s]._max, A[s ^ 1]._max), A[s]._max -= a, A[s ^ 1]._max -= a, A[s >> 1]._max += a;
        a = max(A[t]._max, A[t ^ 1]._max), A[t]._max -= a, A[t ^ 1]._max -= a, A[t >> 1]._max += a;
    }
    for (lc += rc; s; s >>= 1)
    {
        A[s >> 1].sum += v * lc;
        a = min(A[s]._min, A[s ^ 1]._min), A[s]._min -= a, A[s ^ 1]._min -= a, A[s >> 1]._min += a;
        a = max(A[s]._max, A[s ^ 1]._max), A[s]._max -= a, A[s ^ 1]._max -= a, A[s >> 1]._max += a;
    }
}
//单点查询
int query_node(int x,int ans = 0)
{
    for (x += m; x; x >>= 1)
        ans += A[x]._min;
    return ans;
}
//区间查询
ll query_sum(int s, int t)
{
    ll lc = 0, rc = 0, len = 1, ans = 0;
    for (s += m - 1, t += m + 1; s ^ t ^ 1; s >>= 1, t >>= 1, len <<= 1)
    {
        if (s & 1 ^ 1)
            ans += A[s ^ 1].sum + len * A[s ^ 1].add, lc += len;
        if (t & 1)
            ans += A[t ^ 1].sum + len * A[t ^ 1].add, rc += len;
        if (A[s >> 1].add)
            ans += A[s >> 1].add * lc;
        if (A[t >> 1].add)
            ans += A[t >> 1].add * rc;
    }
    for (lc += rc,s >>= 1; s; s >>= 1)
        if (A[s].add)
            ans += A[s].add * lc;
    return ans;
}

int query_min(int s, int t, int L = 0, int R = 0, int ans = 0)
{
    if (s == t)
        return query_node(s);
    for (s += m, t += m; s ^ t ^ 1; s >>= 1, t >>= 1)
    {
        L += A[s]._min, R += A[t]._min;
        if (s & 1 ^ 1)
            L = min(L, A[s ^ 1]._min);
        if (t & 1)
            R = min(R, A[t ^ 1]._min);
    }
    for (ans = min(L, R), s >>= 1; s; s >>= 1)
        ans += A[s]._min;
    return ans;
}

int query_max(int s, int t, int L = 0, int R = 0, int ans = 0)
{
    if (s == t)
        return query_node(s);
    for (s += m, t += m; s ^ t ^ 1; s >>= 1, t >>= 1)
    {
        L += A[s]._max, R += A[t]._max;
        if (s & 1 ^ 1)
            L = max(L, A[s ^ 1]._max);
        if (t & 1)
            R = max(R, A[t ^ 1]._max);
    }
    for (ans = max(L, R), s >>= 1; s; s >>= 1)
        ans += A[s]._max;
    return ans;
}


int main()
{
//    ios::sync_with_stdio(false);
    n = read();
    q = read();
    build();
    int f = 0, x, y, v;
    while (q--)
    {
        f = read();
        if (f == 1)
        {
            x = read();
            y = read();
            v = read();
            update_part(x, y, v);
        }
        else
        {
            x = read();
            y = read();
            printf("%lld\n",query_sum(x, y));
        }
    }
    return 0;
}
