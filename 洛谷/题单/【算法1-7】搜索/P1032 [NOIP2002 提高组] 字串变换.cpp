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
#include <unordered_map>
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
int t, n, ans = 0, all;
string s1, s2, tmp;
struct node {
	string s;
	int st;
};
string fr[1005], to[1005];
unordered_map<string, bool> vis;
string tran(string &str, int i, int j) {
	string ans;
	if (i + fr[j].size() > str.size()) return ans;
	for (int k = 0; k < fr[j].size(); k++)
		if (str[i + k] != fr[j][k]) return ans;
	ans = str.substr(0, i);
	ans += to[j];
	ans += str.substr(i + fr[j].size());
	return ans;
}

int bfs() {
	queue<node> Q;
	Q.push({s1, 0});
	vis[s1] = 1;
	while (Q.size()) {
		node top = Q.front();
		Q.pop();		
		if (top.st > 10)
			return -1;
		if (top.s == s2)
			return top.st;

		for (int i = 0; i < top.s.size(); i++) 
			for (int j = 0; j < all; j++) {
				string ss = tran(top.s, i, j);
				if (ss != "" && !vis[ss]) {
					vis[ss] = 1;
					Q.push({ss, top.st + 1});
				}
			}
	}
	return -1;
}

void solve() {
	cin >> s1 >> s2;
	while (cin >> fr[all]) cin >> to[all++];
	int ans = bfs();
	if (~ans) cout << ans << endl;
	else cout << "NO ANSWER!\n";
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

