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
ll ans = 0;

inline int lowbit(int x) {
	return x & -x;
}
void solve()
{
	cin >> t;
	while (t--) {
		n = read();
		
		string str = "";
		for (int i = 0; i < n; i++) {
			str += '9';
		}
		int s = n / 4;
		for (int i = n - 1 - s; i < n; i++) {
			str[i] = '0';
		}
		if (n % 4 != 0) {
			str[n - s - 1] = '8';
		} else {
			str[n - s - 1] = '9';
		}
		cout << str << endl;
	}
}
/*
10 nyy
2
3
4
5
6
7
8
9
10
9999999999999999999999999999999999999999999999999999999999999999999999999990000000000000000000000000
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

