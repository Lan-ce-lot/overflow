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
#define lowbit(x) x & -x
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;
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
区间和
==============================*/
ll e[maxn * 4];
int n;
// 单点更新
void update(int i, int k) {
    while (i <= n) {
        e[i] += k;
        i += lowbit(i);
    }
}
// 前缀getsum(y) - getsum(x-1);
// x-y区间和也就等于1-y区间和减去1-(x-1)区间和
ll getsum(int i) {
    ll res = 0;
    while (i > 0) {
        res += e[i];
        i -= lowbit(i);
    }
    return res;
}
// 初始化
void init(int a[]) {
    for (int i = 1; i <= n; i++) update(i, a[i]);
}

/*==============================

==============================*/
void solve()
{
    cin >> t;
    int con = 1;
    while (t--) {
        memset(e, 0, sizeof e);
        memset(a, 0, sizeof a);

        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        init(a);
        string s;
        cout << "Case " << con++ << ':' << endl;
        while (cin >> s) {
            int x, y;
            if (s[0] == 'Q') {
                cin >> x >> y;
                cout << getsum(y) - getsum(x - 1) << endl;
            } else if (s[0] == 'A') {
                cin >> x >> y;
                update(x, y);
            } else if (s[0] == 'S') {
                cin >> x >> y;
                update(x, -y);
            } else if (s[0] == 'E') {
                break;
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

