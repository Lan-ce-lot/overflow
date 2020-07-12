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
const int maxn = 50005;

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

struct node
{
    int l, r;
    int val;
}tree[maxn * 4];

int a[maxn];

void build(int p, int l, int r)
{
    tree[p].l = l;
    tree[p].r = r;
    if (l == r)
    {
        tree[p].val = a[l];
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);
        tree[p].val = tree[2 * p].val + tree[2 * p + 1].val;
        return;
    }
}

void update(int p, int x, int k)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].val += k;
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
    tree[p].val = tree[2 * p].val + tree[2 * p + 1].val;
    return;
}

int query(int p, int l, int r)
{
    if (l <= tree[p].l && tree[p].r <= r)
    {
        return tree[p].val;
    }
    int mid = (tree[p].l + tree[p].r) / 2;
    if (r <= mid)
    {
        return query(p * 2, l, r);
    }
    else if (l > mid)
    {
        return query(p * 2 + 1, l, r);
    }
    return query(p * 2, l, mid) + query(p * 2 + 1, mid + 1, r);
}

int t, n;
void solve()
{
    cin >> t;
    int co = 0;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
        }

        build(1, 1, n);
        string str;
        printf("Case %d:\n", ++co);
        while (cin >> str)
        {
            int a, b, c;
            if (str == "End")
                break;
            if (str == "Query")
            {
                a = read();
                b = read();
                cout << query(1, a, b) << endl;
            }
            if (str == "Add")
            {
                a = read();
                b = read();
                update(1, a, b);
            }
            if (str == "Sub")
            {
                a = read();
                b = read();
                update(1, a, -b);
            }
        }
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

