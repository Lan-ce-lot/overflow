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

void solve()
{
	t = read();
	while (t--) {
		string s1, s2, s3, anss1, anss2;
		cin >> s1 >> s2;
//		if (s1.size() < s2.size()) {
//			s3 = s1;
//			s1 = s2;
//			s2 = s3;
//		}
		int lcm = 0;
		lcm =  s1.size() * s2.size() / __gcd(s1.size(), s2.size());
//		cout << lcm << endl;
		int s11 = lcm / s1.size();
		int s22 = lcm / s2.size();
//		cout << s11 << ' ' << s22 << endl;
		for (int i = 0; i < s11; i++) {
			anss1 += s1;
		}
		for (int i = 0; i < s22; i++) {
			anss2 += s2;
		}
//		cout << anss1 << ' ' << anss2 << endl;
		if (anss1 == anss2) {
			cout << anss1 << endl;
		} else {
			cout << -1 << endl;
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

