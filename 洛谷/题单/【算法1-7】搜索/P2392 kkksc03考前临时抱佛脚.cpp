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
int t, n;
int s[5], le, re;
int tm[5][21];
bool vis[5][21];
int ans = INF, res, tmp = INF;
void dfs(int l, int r) {
	if (l > s[r]) {
		tmp = min(tmp, max(le, re));
//		debug(tmp);
//		cout << le << re << endl;
		return ;
	}

		// 
		le += tm[r][l];
		dfs(l + 1, r);
		le -= tm[r][l];
		
		
		re += tm[r][l];
		dfs(l + 1, r);
		re -= tm[r][l];

}

void solve()
{
	res = 0;
	for (int i = 1; i <= 4; i++) cin >> s[i];
	for (int i = 1; i <= 4; i++) {
		le = 0, re = 0;
		for (int j = 1; j <= s[i]; j++) {
			cin >> tm[i][j];
		}
		tmp = INF;
		dfs(1, i);
		
		res += tmp;
//		cout << res << endl;
	} 
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

