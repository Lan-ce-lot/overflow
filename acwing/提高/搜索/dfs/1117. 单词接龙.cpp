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
#include <unordered_map>
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
string str[25];

unordered_map<string, int> M;

bool test (string a, string b, int &c) {
	int len = 0;
	for (int i = 0; i < b.size() && i < a.size(); i++) {
		if (a.substr(a.size() - i - 1, i + 1) == b.substr(0, i + 1)) {
			len = i + 1;
			c = len;
			if (i + 1 >= b.size() || i + 1 >= a.size()) return 0;
			return 1;
		}
	}
	
//	if (len >= b.size() || len)
	return 0;
}
int len = 0;
string ans;
void dfs(string res, int st) {
	if (ans.size() < res.size()) {
		ans = res;
	}
	for (int i = 0; i < n; i++) {
		string tem = str[i];
		int c = 0;
//		cout << tem << M[tem] << endl;
		if (M[tem] < 2) {
			if (test(res, tem, c)) {
				M[tem] ++;
//				res = 
//				ans = ans.size() > res.size() ? ans : res;
//				cout << st << ' ' << res << ' ' <<tem << ' ' << res.substr(0, res.size() - c) + tem <<  endl;
				dfs(res.substr(0, res.size() - c) + tem, st + 1);
				M[tem] --;				
			}

		}
	}
}

void solve()
{
//	cout << test("tact", "tact", t);
	n = read();
	
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	char st[2];
	cin >> st;
	for (int i = 0; i < n; i++) {
		string tem = str[i];
		if (tem[0] == *st) {
			M[tem] ++;
			dfs(tem, 1);
			M[tem] --;	
		}

	}
//	debug(ans);
	cout << ans.size() << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

