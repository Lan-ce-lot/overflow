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
int t, n, ans, vis[maxn];
string str[25];
string res;
bool check(string s1, string s2) {
	bool flag = 0;
	for (int len = 1; len < min(s1.size(), s2.size()); len++) {
		flag = 0;
		for (int i = s1.size() - len, j = 0; i < s1.size() && j < len; i++, j++) {
			if (s2[j] != s1[i]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			res = s1.substr(0, s1.size() - len) + s2;
			return 1;
		}
	}
	return 0;
}
map<string, bool> M;
void dfs(int all, string s) {
//	if (all == n) {
//		
//		return;
//	}
/*
5
at
touch
cheat
choose
tact
a
1 2 3 5 5 2 4
at touch cheat tact tact touch choose
atoucheat
*/
	for (int i = 1; i <= n; i++) {
		if (vis[i] < 2 && check(s, str[i])) {
			if (M[res]) continue;
			vis[i]++;
			M[res] = 1;
//			debug(res);
//			debug(res.size());
//			cout << "_______" << endl;
			dfs(all + 1, res);
			vis[i]--;
			M[res] = 0;
		}
	}

	ans = max(ans, int(s.size()));
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
	}
	char c;
	cin >> c;
	for (int i = 1; i <= n; i++) {
		if (str[i][0] == c) {
			vis[i] ++;
			dfs(1, str[i]);
			vis[i] --;
		}
	}
	
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

