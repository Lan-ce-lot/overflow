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
#define x first
#define y second
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
unordered_map<string, bool> vis;
bool check(string str) {
	bool flag = 0;
	for (int i = 1; i <= str.size(); i++) {
		if (str[i] == str[i - 1]) {
			return 0;
		}
	}
	return 1;
//	
//	str += (str[str.size() - 1] == '0' ? '1' : '0');
////	debug(str);
//	string tem = str;
//	reverse(str.begin(), str.end());
//	if (str == tem) return 1;
//	else return 0;
	
}

void bfs(string str, int step) {
	queue<pair<string, int> > Q;
	Q.push({str, 0});
	while (Q.size()) {
		pair<string, int> top = Q.front();
		Q.pop();
		
		if (check(top.x)) {
			cout << top.y << endl;
			return ;
		}
//		string tem = 
		for (int i = 0; i < top.x.size(); i++) {
			for (int j = 2; j <= top.x.size() - i; j++) {
				string s = top.x.substr(i, j);
				reverse(s.begin(), s.end());
				
				string to = top.x.substr(0, i) + s + top.x.substr(i + j, top.x.size() - i - j);
				if (vis[to] == 0) {
//					debug(to);
					Q.push({to, top.y + 1});
					vis[to] = 1;
				}
			}
		}
		/*
4
4
0110
		*/
	}
	
		
}

vector<int> h_0;
vector<int> h_1;
void solve()
{
	
	t = read();
	while (t--) {
		h_0.clear();
		h_1.clear();
		vis.clear();
		n = read();
		string str;
		cin >> str;
//		bfs(str, 0);
//		cout << check(str);
		char tem = '3';
		int con = 1;
		for (int i = 0; i < n; i++) {
			
			if (str[i] == tem) {
				con++;
			} else {
				if (con >= 2 && tem == '1') {
					h_1.push_back(con);
				} else if (con >= 2 && tem == '0') {
					h_0.push_back(con);
				}
				con = 1;
			}
			tem = str[i];
		}
		int ans_0 = 0, ans_1 = 0;
		for (int i = 0; i < h_0.size(); i++) {
			ans_0 += h_0[i] - 1;
		}
		for (int i = 0; i < h_1.size(); i++) {
			ans_1 += h_1[i] - 1;
		} 
		cout << max(ans_0, ans_1) << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

