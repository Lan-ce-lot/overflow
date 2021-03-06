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
map<int, string> ge = {{0, "tret"}, {1, "jan"}, {2, "feb"}, {3, "mar"}, {4, "apr"}, {5, "may"}, 
{6, "jun"}, {7, "jly"}, {8, "aug"}, {9, "sep"}, {10,  "oct"}, {11, "nov"}, {12, "dec"}, 
{13, "tam"}, {13 * 2, "hel"}, {13 * 3, "maa"}, {13 * 4, "huh"}, {13 * 5, "tou"}, {13 * 6, "kes"}, 
{13 * 7, "hei"}, {13 * 8, "elo"}, {13 * 9, "syy"}, {13 * 10, "lok"}, {13 * 11, "mer"}, {13 * 12, "jou"}};
map<string, int> r_ge = {{"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, 
{"jun", 6}, {"jly", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10} , {"nov", 11}, {"dec", 12},
{"tam", 13}, {"hel", 13 * 2}, {"maa", 13 * 3}, {"huh", 13 * 4}, {"tou", 13 * 5}, {"kes", 13 * 6}, 
{"hei", 13 * 7}, {"elo", 13 * 8}, {"syy", 13 * 9}, {"lok", 13 * 10}, {"mer", 13 * 11}, {"jou", 13 * 12}};


void solve()
{
	t = read();
	while (t--) {
		string str;
		getline(cin, str);
		if (str[0] >= 'a' && str[0] <= 'z') {
			if (str.size() > 3) {
				string h = str.substr(0, 3);
				string l = str.substr(4, 3);
				cout << r_ge[h] + r_ge[l] << endl;
			} else {
				cout << r_ge[str] << endl;
			}
		} else {
			int num = 0;
			for (int i = 0; i < str.size(); i++) {
				num *= 10;
				num += (str[i] - '0');
			}
			if (num / 13 && num % 13) {
				cout << ge[num - num % 13] << ' ' << ge[num % 13] << endl;
			} else if (num % 13) {
				cout << ge[num % 13] << endl;
			} else {
				cout << ge[num] << endl;
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

