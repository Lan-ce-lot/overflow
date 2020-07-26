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
int a[maxn];
void solve()
{
	cin >> t;
	while (t--) {
		n = read();
		int max_a = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = read();
			max_a = max(max_a, a[i]);
		}
		// a b
//		map<int, char> M;
//		M[0] = 'a';
//		M[1] = 'b';
//		map<char, int> M1;
//		M1['a'] = 1;
//		M1['b'] = 0;
		if (max_a == 0) {
			for (int i = 0; i <= n; i++) {
				if (i & 1) cout << 'a' << endl;
				else cout << 'b' << endl;
			}
			continue;
		}
		string a1 = "", b1 = "", tem;
		for (int i = 1; i <= max_a; i++) a1 += "a";
		cout << a1 << endl;
//		puts("");
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < max_a; j++) {
				if (i & 1) {
					if (j == 0) b1 = "";
					if (j < a[i]) {
						b1 += a1[j];
					}
					else {
						b1 += char('a' + (a1[j] - 'a' + 1) % 26);
					}
				} else {
					if (j == 0) a1= "";
					if (j < a[i]) {
						a1 += b1[j];
					} else {
						a1 += char('a' + (b1[j] - 'a' + 1) % 26);
					}
				}
			}
			if (i & 1) {
				cout << b1 << endl;
			} else {
				cout << a1 << endl;
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

