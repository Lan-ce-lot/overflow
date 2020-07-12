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
const int mod = 998244353;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 200005;

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
int t, n, k;
ll a[maxn];

struct node
{
    ll l, r, v;
}tree[maxn << 2];

void pushup(int p)
{
    tree[p].v = (tree[p * 2].v % mod * tree[p * 2 + 1].v % mod) % mod;
}

void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    if (l == r)
    {
        tree[p].v = a[l];
        return ;
    }
    int m = tree[p].l + tree[p].r >> 1;
    build(p * 2, l, m);
    build(p * 2 + 1, m + 1, r);
    pushup(p);
    return;
}

ll query(int p, int l, int r)
{
    if (l == tree[p].l && r == tree[p].r)
    {
        return tree[p].v % mod;
    }
    int m = tree[p].l + tree[p].r >> 1;
    if (r <= m)
    {
        return query(p * 2, l, r) % mod;
    }
    if (l > m)
    {
        return query(p * 2 + 1, l, r) % mod;

    }
    return (query(p * 2, l, m) % mod * query(p * 2 + 1, m + 1, r) % mod) % mod;
}

void solve()
{
    ll ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    build(1, 1, n);
    for (int i = 1; i <= n - k + 1; i++)
    {
        ans = max(ans, query(1, i, i + k - 1));
    }
    cout << ans << endl;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

