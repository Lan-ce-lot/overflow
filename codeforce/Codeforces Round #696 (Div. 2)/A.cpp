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
string str;

void solve()
{
	int t = read();
	while (t--) {
		n = read();
		cin >> str;
		string ans = "";
		// 1 + 1
		// 1 + 0
		// 0 + 1
		// 0 + 0
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				flag = str[i] - '0' + 1;
				ans += "1";
			} else {
				if (flag == 2) {
					if (str[i] == '0') {
						ans += "1";
						flag = 1;
					} else {
						ans += "0";
						flag = 1;
					}
				} else if (flag == 1) {
					if (str[i] == '0') {
						ans += "0";
						flag = 0;
					} else {
						ans += "1";
						flag = 2;
					}
				} else if (flag == 0) {
					if (str[i] == '0') {
						ans += "1";
						flag = 1;
					} else {
						ans += "1";
						flag = 2;
					}
				}
			}
		}
		 
		cout << ans << endl;
		
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

