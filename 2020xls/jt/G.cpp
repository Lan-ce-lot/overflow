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
ll t, n, ans = 0;
int dp[100][7][7]; //step, fa, cnt 
int num[10];
void dfs(int n, int step, int fa) {
	if (step >= n) {
		int tem = 0;
		for (int i = 1; i <= 6; i++) {
			if (num[i] >= 1) {
				tem++;
			}
			
		}
		if (tem >= 3) ans++;
		return;
	}
	for (int i = 1; i <= 6; i++) {
		if (abs(fa - i) < 5) {
			num[i]++;
			dfs(n, step + 1, i);
			num[i]--;
		}
	}
}/* 
3
104
4
904
5
5880
6
35080
7
203224
8
1165224
9
6656760
10
37980360
11
216600344
12
1235066344
13
7042019640
14
40150936840
15
228923909464
*/ 
void solve()
{
// yaoshi
// 3
	while (~scanf("%lld", &n)) {
		ans = 0;
		dfs(n, 0, 3);
		cout << ans << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

