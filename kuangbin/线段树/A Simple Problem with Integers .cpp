/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description://https://vjudge.net/problem/POJ-3468
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
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

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

int a[maxn];
struct node
{
    ll lazy, v;
    int l,r;
}tree[maxn * 4];

void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;

    if (l == r)
    {
        tree[p].v = a[l];
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    tree[p].v = tree[p * 2].v + tree[p * 2 + 1].v;
}

void pushdown(int p)
{
    if (tree[p].lazy)
    {
        tree[p * 2].lazy += tree[p].lazy;
        tree[p * 2 + 1].lazy += tree[p].lazy;
        tree[p * 2].v += tree[p].lazy * (tree[2 * p].r - tree[p * 2].l + 1);
        tree[p * 2 + 1].v += tree[p].lazy * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
        tree[p].lazy = 0;
    }
}

void update(int p, int l, int r, int k)
{
    if (tree[p].l == l && tree[p].r == r)
    {
        tree[p].lazy += k;
        tree[p].v += k * (r - l + 1);
        return;
    }
    if (tree[p].l == tree[p].r)
        return;
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if (r <= mid)
    {
        update(2 * p, l, r, k);
    }
    else if (l > mid)
    {
        update(2 * p + 1, l, r, k);
    }
    else
    {
        update(2 * p, l, mid, k);
        update(2 * p + 1, mid + 1, r, k);
    }

    tree[p].v = tree[p * 2].v + tree[p * 2 + 1].v;
}

ll query(int p, int l, int r)
{
    if(tree[p].l == l && tree[p].r == r)
        return tree[p].v;
    pushdown(p);
    int mid = (tree[p].l +tree[p].r) / 2;
    if (r <= mid)
        return query(p * 2, l, r);
    if (l > mid)
        return query(p * 2 + 1, l, r);
    return query(2 * p, l, mid) + query(2 * p + 1, mid + 1, r);
}


int t, n, q;

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    string c;
    int x, y, z;
    while (q--)
    {
        cin >> c;
        if (c == "Q")
        {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(1, x, y));
        }
        else
        {
            scanf("%d %d %d", &x, &y, &z);
            update(1, x, y, z);
        }
    }
}


int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

