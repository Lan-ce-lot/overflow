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
//#define lowbit(x) x & (-x)
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 300005;
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
int t, a[maxn];
/*==============================
树状数组
区间最值
==============================*/
inline int lowbit(int x)
{
	return x & (-x);
}
int e[maxn];
int n, m;
// 单点更新
void update(int x) {
    int lx, i;
    while (x <= n) {
        e[x] = a[x];
        lx = lowbit(x);
        for (i = 1; i < lx; i <<= 1)
            e[x] = max(e[x], e[x - i]);
        x += lowbit(x);
    }
}

// 区间最值
int query(int x, int y) {
    int ans = 0;
    while (y >= x) {
        ans = max(a[y], ans);
        y--;
        for (; y - lowbit(y) >= x; y -= lowbit(y))
            ans = max(e[y], ans);
    }
    return ans;
}
// 初始化
void init(int a[]) {
    for (int i = 1; i <= n; i++) update(i);
}

/*==============================

==============================*/
void solve()
{
    int x, y, ans;
	char c;
    while (scanf("%d%d", &n, &m) != EOF) {
		for (int i=1; i<=n; i++)
			e[i] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            update(i);
        }
//        init(a);
        for (int i = 1; i <= m; i++) {
			scanf("%c",&c);
			scanf("%c",&c);
            if (c == 'Q') {
                scanf("%d%d", &x, &y);
                ans = query(x, y);
                printf("%d\n",ans);
            } else if (c == 'U') {
                scanf("%d%d", &x, &y);
                a[x] = y;
                update(x);
            }
        }
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
