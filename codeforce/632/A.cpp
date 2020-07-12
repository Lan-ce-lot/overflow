/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
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
int t, n, m;
int a[maxn], b[maxn];
ll ans = 0;
char ma[105][105];
struct node {
    int l, r;

    int val;
}tree[maxn * 4];

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].val = a[l];
//        if (tree[p].val) {
//            ans++;
//            cout << l << ' ' << r << endl;
//            debug(tree[p].val);
//        }
        return;
    } else {
        int mid = (l + r) / 2;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);
        tree[p].val = tree[2 * p].val + tree[2 * p  + 1].val;
//        if (tree[p].val) {
//            ans++;
//            cout << l << ' ' << r << endl;
//            debug(tree[p].val);
//        }
        return;
    }
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



void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cout << ans << endl;
//    for (int i = 0 ; i < n * 4; i++) {
//        cout << tree[i].val <<endl;
//    }
    ans= 0;

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

