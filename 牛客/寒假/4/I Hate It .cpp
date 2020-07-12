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
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 2 * 1e5 + 5;

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






int t, n, q, a[maxn];

struct node
{
    int l, r, MAX;
} tree[maxn * 4];

void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    if (tree[p].l == tree[p].r)
    {
        tree[p].MAX = a[l];
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    tree[p].MAX = max(tree[p * 2].MAX, tree[p * 2 + 1].MAX);
    return;
}

void update(int p, int x, int k)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].MAX = k;
        return;
    }

    int mid = (tree[p].l + tree[p].r) / 2;
    if (x <= mid)
    {
        update(2 * p, x, k);
    }
    else
    {
        update(2 * p + 1, x, k);
    }


    tree[p].MAX = max(tree[p * 2].MAX, tree[p * 2 + 1].MAX);
    return;
}

int query(int p, int l, int r)
{
    if (l == tree[p].l && tree[p].r == r)
    {
        return tree[p].MAX;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (r <= mid)
    {
        return query(p * 2, l, r);
    }
    if (l > mid)
    {
        return query(p * 2 + 1, l, r);
    }
    return max(query(p * 2, l, mid), query(p * 2 + 1, mid + 1, r));
}

void solve()
{
    while (cin >> n >> q)
    {
        for (int i = 1; i <= n; i++)
            a[i] = read();
        build(1, 1, n);
        while (q--)
        {
            char c;
            int x, y;
            cin >> c;
            cin >> x >> y;
            if (c == 'Q')
            {
                cout << query(1, x, y) << endl;
            }
            else
                update(1, x, y);
        }
    }
}


int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

