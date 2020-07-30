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
const int maxn = 100005;
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
vector<int> left1, right1;
int check_l(string s) {
	stack<char> S;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			S.push(s[i]);
			left1.push_back(i);
		} else if (S.size() && s[i] == ')'){
			S.pop();
			left1.pop_back();
		}
	}
	return S.size();
}
int check_r(string s) {
	stack<char> S;
	for (int i = s.size() - 1; i >= 0; i--) {
		if(s[i] == ')') {
			S.push(s[i]);
			right1.push_back(i);
		} else if (S.size() && s[i] == '('){
			S.pop();
			right1.pop_back();
		}
	}
	return S.size();
}
int vis[maxn];
string change(string s) {
	string str = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*' && vis[i] == -1) {
			str += '(';
		} else if (s[i] == '*' && vis[i] == 1){
			str += ')';
		} else if (s[i] != '*') {
			str += s[i];
		}
	}
	return str;
}

bool check(string str) {
	stack<char> S;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			S.push('(');
		} else if (str[i] == ')'){
			if (!S.empty())
				S.pop();
			else {
				return 0;
			}
		}
	}
//	debug(S.size());
	return S.empty();
}
void solve()
{
	t = read();
	while (t--) {
//		memset(vis, 0, sizeof vis);
		left1.clear(), right1.clear();
		string str, str1;
		cin >> str;
		n = str.size();
		int ch_l = check_l(str);
		int ch_r = check_r(str);
//		cout << ch_r << ' ' << ch_l << endl;
//		cout << check_l(str) <<' '  << check_r(str) << endl;
//		for (auto i : left1) {
//			cout << i << ' ';
//			
//		}puts("");
//		for (auto i : right1) {
//			cout << i << ' ';
//		}puts("");
		int count_l = 0, count_r = 0, star = 0;
		for (int i = 0; i < n; i++) {
			vis[i] = 0;
			if (str[i] == '(') {
				count_l ++;
				str1 += str[i];
			} else if (str[i] == ')') {
				count_r ++;
				str1 += str[i];
			} else if (str[i] == '*') {
				star++;
			}
		}
		if (0) {
//		if (star + count_l < count_r || star + count_r < count_l) {
//			puts("No solution!");
		} else {
			if (ch_l > 0) {
//				if ()
				for (int i = n - 1; i >= 0; i--) {
					if (str[i] == '*') {
						vis[i] = 1;ch_l--;
					}
					
					if (ch_l <= 0) break;
				}
			}
			if (ch_r > 0) {
				for (int i = 0; i < n; i++) {
					if (str[i] == '*') {
						vis[i] = -1;ch_r--;
					}
					if (ch_r <= 0) break;
				}				
			}
//			if (count_l > count_r) {
//				
//			}
//			if (count_l < count_r) {
//				
//			}
//			if (count_l == count_r) {
//				
//			}
/*
6
()*()
*/
		string sss = change(str);
//		cout << sss << endl;
//		cout << sss.size() << endl;
		if (check(sss)) {
//			cout << check_r(sss) << check_l(sss) << endl;
			cout << sss << endl;
		} else {
			puts("No solution!");
		}
		}
	}
}


/*
炸点
炸边
最短路
最长的
最短路 
1-n 
*/

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

