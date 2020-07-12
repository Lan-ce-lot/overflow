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
int t, n, q;
struct node
{
    int l, r, v;
    int lazymul;
} tree[maxn * 4];

void build(int p, int l, int r)
{
    tree[p].lazymul = 0;
    tree[p].l = l, tree[p].r = r;
    if (tree[p].l == tree[p].r)
    {
        tree[p].v = 1;
        return;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    tree[p].v = tree[p * 2].v + tree[p * 2 + 1].v;
//    cout << p << ' ';debug(tree[p].v);
    return;
}

void pushdown(int p, int l, int r)
{
    if (tree[p].lazymul)
    {
        tree[p * 2].lazymul = tree[p * 2 + 1].lazymul = tree[p].lazymul;
        tree[p * 2].v = l * tree[p].lazymul;
        tree[p * 2 + 1].v = r * tree[p].lazymul;

        tree[p].lazymul = 0;
    }

    return;
}

void mul(int p, int l, int r, int k)
{
    if (l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].v = k * (tree[p].r - tree[p].l + 1);
        tree[p].lazymul = k;
        return;
    }

    int mid = (tree[p].l + tree[p].r) / 2;
    pushdown(p, mid - tree[p].l + 1, tree[p].r - mid);
    if (l <= mid)
    {
        mul(2 * p, l, r, k);
    }
    if (mid < r)
    {
        mul(2 * p + 1, l, r, k);
    }
    tree[p].v = tree[p * 2].v + tree[p * 2 + 1].v;
    return ;

}


void solve()
{
    cin >> t;
    int co = 0;
    while (t--)
    {
        co++;
        n = read();
        q = read();
        build(1, 1, n);
        for (int i = 1; i <= q; i++)
        {
            int a, b, c;
            a = read();
            b = read();
            c = read();
            mul(1, a, b, c);
        }
        cout << "Case " << co << ": The total value of the hook is ";
        cout << tree[1].v << '.' << endl;
    }
}

int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}
