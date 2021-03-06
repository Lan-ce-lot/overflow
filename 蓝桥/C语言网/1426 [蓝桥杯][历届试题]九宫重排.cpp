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
int t, n;
string from, to, ans; 

struct node {
	string tem;
	int step;
};
unordered_map<string, bool> vis;
			// you
			// xia
			// zuo
			// shang
string st(string s, int x, int y, int flag) {
	char tem;
	if (flag == 0) {
		tem = s[x * 3 + y];
		s[x * 3 + y] = s[x * 3 + y + 1];
		s[x * 3 + y + 1] = tem;
	} else if (flag == 1) {
		tem = s[x * 3 + y];
		s[x * 3 + y] = s[x * 3 + y + 3];
		s[x * 3 + y + 3] = tem;
	} else if (flag == 2) {
		tem = s[x * 3 + y];
		s[x * 3 + y] = s[x * 3 + y - 1];
		s[x * 3 + y - 1] = tem;
	} else if (flag == 3) {
		tem = s[x * 3 + y];
		s[x * 3 + y] = s[x * 3 + y - 3];
		s[x * 3 + y - 3] = tem;
	}
	return s;
}

int bfs(string from) {
	queue<node> Q;
	Q.push({from, 0});
	vis[from] = 1;
	
	while (Q.size()) {
		node top = Q.front();
		Q.pop();
		
		if (top.tem == to) {
			return top.step;
		}
		if (top.step > 30) {
			break;
		}
		int we = 0;
		for (int i = 0; i < 9; i++) {
			if (top.tem[i] == '.') {
				we = i;
			}
		}
		int xx = we / 3, yy = we % 3;
		string tt;
		for (int i = 0; i < 4; i++) {
			// you
			// xia
			// zuo
			// shang
			if (xx == 0 && i == 3) {
				continue;
			} else if (xx == 2 && i == 1) {
				continue;
			} else if (yy == 0 && i == 2) {
				continue;
			} else if (yy == 2 && i == 0) {
				continue;
			}
//			cout << i << endl;
			tt = st(top.tem, xx, yy, i);
			if (!vis[tt]) {
				vis[tt] = 1;
				Q.push({tt, top.step + 1});
			}
		}
	}
	return -1;
}

void solve()
{
	cin >> from >> to;
	cout << bfs(from) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

