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
const int maxn = 100005;

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
int t, n;

struct node
{
    int l, r;
    ll lazy, v;
}tree[maxn << 2];
int a[maxn];
void pushup(int p)
{
    tree[p].v = tree[p * 2].v + tree[p * 2 + 1].v;
}

void pushdown(int p)
{
    if (tree[p].lazy)
    {
        tree[p * 2].lazy += tree[p].lazy;
        tree[p * 2 + 1].lazy += tree[p].lazy;
        tree[p * 2].v += tree[p].lazy * (tree[p * 2].r -tree[p * 2].l + 1);
        tree[p * 2 + 1].v += tree[p].lazy * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
        tree[p].lazy = 0;
    }
}

void build(int p, int l, int r)
{
    tree[p].l = l, tree[p].r = r;
    tree[p].lazy = 0, tree[p].v = 0;
    if (l == r)
    {
        return;
    }
    int m = l + r >> 1;
    build(p * 2, l, m);
    build(p * 2 + 1, m + 1, r);
    pushup(p);
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
    int m = tree[p].l + tree[p].r >> 1;
    if (r <= m)
    {
        update(2 * p, l, r, k);
    }
    else if (l >= m)
    {
        update(2 * p + 1, l, r, k);
    }
    else
    {
        update(2 * p, l, m, k);
        update(2 * p + 1, m + 1, r, k);
    }
    pushup(p);
}

ll query(int p, int l, int r)
{
    if (l == tree[p].l && tree[p].r == r)
    {
        return tree[p].v;
    }
    int m = tree[p].l + tree[p].r >> 1;
    pushdown(p);
    if (r <= m)
        return query(p * 2, l, r);
    if (l > m)
        return query(p * 2 + 1, l, r);
    return query(p * 2, l , m) + query(p * 2 + 1, m + 1, r);
}


void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int Max = *max_element(a + 1, a + 1 + n);
    build(1, 1, Max);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        update(1, a[i], a[i], 1);

        sum += i - query(1, 1, a[i]);
    }
    cout << sum << endl;
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

