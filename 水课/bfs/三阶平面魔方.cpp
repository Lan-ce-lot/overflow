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

#define x first
#define y second
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
map<string, bool> M;
string change(string s, int flag, int j) {
	if (flag == 0) { // l
		char c = s[j * 3];
		s[j * 3] = s[j * 3 + 1];
		s[j * 3 + 1] = s[j * 3 + 2];
		s[j * 3 + 2] = c;
	} else if (flag == 1) { // r
		char c = s[j * 3 + 2];
		s[j * 3 + 2] = s[j * 3 + 1];
		s[j * 3 + 1] = s[j * 3];
		s[j * 3] = c;
	} else if (flag == 2) { // u
		char c = s[j];
		s[j] = s[j + 3];
		s[j + 3] = s[j + 6];
		s[j + 6] = c;
	} else if (flag == 3) { // d
		char c = s[j + 6];
		s[j + 6] = s[j + 3];
		s[j + 3] = s[j];
		s[j] = c;		
	}
	return s;
}

string res = "123456789";
int bfs(string str, int step) {
	queue<pair<string, int> > Q;
	Q.push({str, step});
	M[str] = 1;
	while (!Q.empty()) {
		pair<string, int> top = Q.front();
		Q.pop();
//		cout << top.x << ' ' << top.y  << endl;
		if (top.x == res) {
//			ans = top.y;
			return top.y;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				string tem = change(top.x, i, j);
				if (!M[tem]) {
					M[tem] = 1;
					Q.push({tem, top.y + 1});
				}				
			}

		}
	}
	return -1;
} 


void solve()
{
	int n = 3;
	string str, tem;
	for (int i = 0; i < n; i++) {
		cin >> tem;
		str += tem;
	}
	cout << bfs(str, 0) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

