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

ll a[maxn];
struct noode
{
    ll sum;
    ll lazy;
}A[maxn << 2];

void build(int u, int l, int r)
{
    A[u].lazy = 0;
    if (l == r)
    {
        A[u].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    A[u].sum = A[2 * u].sum + A[2 * u + 1].sum;
}

void pushdown(int u, int l, int r)
{
    if (A[u].lazy == 0)
        return;
    int mid = (l + r) / 2;
    A[u * 2].sum += A[u].lazy * (mid - l + 1);
    A[u * 2 + 1].sum += A[u].lazy * (r - mid);
    A[u * 2].lazy += A[u].lazy;
    A[u * 2 + 1].lazy += A[u].lazy;
    A[u].lazy = 0;
}

void add(int u, int sl, int sr, int l, int r, ll k)
{
    if (l > sr || r < sl)
        return;
    if (l <= sl && r >= sr)
    {
        A[u].sum += k * (sr - sl + 1);
        A[u].lazy += k;
        return;
    }
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    add(2 * u, sl, mid, l, r, k);
    add(2 * u + 1, mid + 1, sr, l, r, k);
    A[u].sum = A[u * 2].sum + A[u * 2 + 1].sum;
    return;
}

ll query(int u, int sl, int sr, int l, int r)
{
    if (l > sr || r < sl)
        return 0;
    if (l <= sl && r >= sr)
        return A[u].sum;
    pushdown(u, sl, sr);
    int mid = (sl + sr) / 2;
    return (query(2 * u, sl, mid, l, r) + query(2 * u + 1, mid + 1, sr, l, r));
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
int t, n;
char flag;
int main()
{
//    ios::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    build(1, 1, n);
    while (t--)
    {
        cin >> flag;
        if (flag == 'Q')
        {
            int a1, b1;
            a1 = read();
            b1 = read();
            cout << query(1, 1, n, a1, b1) << endl;
        }
        else
        {
            int a1, b1, c1;
            a1 = read();
            b1 = read();
            c1 = read();
            add(1, 1, n, a1, b1, c1);
        }
    }
    return 0;
}

