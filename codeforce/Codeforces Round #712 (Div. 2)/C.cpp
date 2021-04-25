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
const int maxn = 300005;
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
string s1, s2, s3 = " ";
int su1[maxn], su2[maxn], su3[maxn];
bool f(int l, int r) {
	for (int i = l; i <= r; i++) if (s1[i] != s2[i]) return 0;
	return 1; 
}
bool f1(int l, int r) {
	for (int i = l; i <= r; i++) if (s1[i] == s2[i]) return 0;
	return 1;
}
void solve()
{
	cin >> t;
	while (t--) {
		cin >> n >> s1 >> s2;
		int ff = 0, l = 0, r = 0, in = 0;
		for (int i = 0; i < n; i++) {
			if (s2[i] == '1') ff++;
			else ff--;
			if (ff == 0) {
				r = i;
				if (!(f(l, r) || f1(l, r))) {
					in = -1;
					break;
				}
				l = r + 1;
			}
		}
		r = n;
		in = (ff && !f(l, r)) ? -1 : in;
		puts(~in? "YES":"NO");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

