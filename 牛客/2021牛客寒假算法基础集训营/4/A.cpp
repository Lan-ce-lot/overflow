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
int t, m, n;
int num[200][3];
bool vis[maxn];
void solve()
{
	set<int> S;
	m = read(), n = read();
	S.clear();
	memset(num, sizeof num, 0);
	for (int i = 0; i < m; i++) {
		int tmp = read();
		num[tmp][0]++;
		string s;
		cin >> s;
		if (s == "AC") {
			num[tmp][1]++;
		} else {
			num[tmp][2]++;
		}
		if (num[tmp][1] >= num[tmp][2] && vis[tmp] == 0) {
			S.insert(tmp);
		} else {
			vis[tmp] = 1;
			S.erase(tmp);
		}
	}

	int len = 0;
	if (S.size() == 0) {
		cout << -1 << endl;
		return;
	} else {
		len = S.size();
	}
	int co = 0;
	for (auto it : S) {
		cout << it;co++;
		if (co < len) {
			cout << " " ;
		} else {
			cout << endl;
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

