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
bool check(string s) {
	stack<char> S;
	int index = 0;
	while (index < s.size()) {
		if (S.empty()) {
			S.push(s[index]);
		} else if (s[index] == ')' && S.top() == '(') {
			S.pop();
		} else {
			S.push(s[index]);
		}
		index++;
	}
	if (S.empty()) {
		return 1;
	} else {
		return 0;
	}
}
void solve()
{
	t = read();
	while (t--) {
		string str;
		cin >> str;
		int co_A = 0, co_B = 0, co_C = 0;
		for (int i = 0 ; i < str.size(); i++) {
			if (str[i] == 'A') {
				co_A ++;
			} else if (str[i] == 'B') {
				co_B++;
			} else {
				co_C++;
			}
		}
		if (str.size() & 1) {
			puts("NO");
			continue;
		} else {
			string tmp = "";
			if (co_A + co_B == co_C) {
				if (str[0] == 'A' || str[0] == 'B') {
					for (int i = 0; i < str.size(); i++) {
						if (str[i] == 'A' || str[i] == 'B') {
							tmp += "(";
						} else {
							tmp += ")";
						}
					}
				} else {
					for (int i = 0; i < str.size(); i++) {
						if (str[i] == 'A' || str[i] == 'B') {
							tmp += ")";
						} else {
							tmp += "(";
						}
					}	
				}
			} else if (co_B + co_C == co_A) {
				if (str[0] == 'C' || str[0] == 'B') {
					for (int i = 0; i < str.size(); i++) {
						if (str[i] == 'C' || str[i] == 'B') {
							tmp += "(";
						} else {
							tmp += ")";
						}
					}	
				} else {
					for (int i = 0; i < str.size(); i++) {
						if (str[i] == 'C' || str[i] == 'B') {
							tmp += ")";
						} else {
							tmp += "(";
						}
					}	
				}
			} else if (co_A + co_C == co_B) {
				if (str[0] == 'A' || str[0] == 'C') {
					for (int i = 0; i < str.size(); i++) {
						if (str[i] == 'A' || str[i] == 'C') {
							tmp += "(";
						} else {
							tmp += ")";
						}
					}	
				} else {
					for (int i = 0; i < str.size(); i++) {
						if (str[i] == 'A' || str[i] == 'C') {
							tmp += ")";
						} else {
							tmp += "(";
						}
					}	
				}
				
			} else {
				puts("NO");
				continue;
			}
			if (check(tmp)) {
				puts("YES");
			} else {
				puts("NO");
			}
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

