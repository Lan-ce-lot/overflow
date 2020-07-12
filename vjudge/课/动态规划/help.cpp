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
int t, n, Max;
struct node{
    int l, r, h;
    bool operator< (const node &W)const{
        return h > W.h;
    }
}range[1005];
int dp[1005][2];

void le(int i) {
    int k = i + 1;
    while (k < n +1 && range[i].h - range[k].h <= Max) {
        if (range[i].l >= range[k].l && range[i].l <= range[k].r) {
            dp[i][0] = range[i].h - range[k].h + min(dp[k][0] + range[i].l - range[k].l, dp[k][1] + range[k].r - range[i].l);
            return;
        }
        k++;
    }
    if (range[i].h - range[k].h > Max) dp[i][0] = INF;
    else dp[i][0] = range[i].h;
    return;
}

void ri(int i) {
    int k = i + 1;
    while (k < n +1 && range[i].h - range[k].h <= Max) {
        if (range[i].r >= range[k].l && range[i].r <= range[k].r) {
            dp[i][1] = range[i].h - range[k].h + min(dp[k][0] + range[i].r - range[k].l, dp[k][1] + range[k].r - range[i].r);
            return;
        }
        k++;
    }
    if (range[i].h - range[k].h > Max) dp[i][1] = INF;
    else dp[i][1] = range[i].h;
    return;

}


void solve()
{
    int x, y;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &x, &y, &Max);
        range[0].l = -INF;
        range[0].r = INF;
        range[0].h = 0;
        range[1].l = range[1].r = x;
        range[1].h = y;
        for (int i = 2; i <= n + 1; i++) {
            scanf("%d%d%d", &range[i].l, &range[i].r, &range[i].h);
        }
        sort(range, range + n + 2);
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 0; i--) {
//                cout << range[i].h << endl;
            le(i);
            ri(i);
        }
        printf("%d\n", min(dp[0][0], dp[0][1]));
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

