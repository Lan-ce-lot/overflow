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
int num[maxn];
int ans_l = 0, ans_r = 0;
int binary0(int a) {
	int l = 0, r = n;
	
	while (l < r) {
		int mid = l + r >> 1;
		if (num[mid] >= a) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
int binary1(int a) {
	int l = 0, r = n;
	
	while (l < r) {
		int mid = l + r >> 1;
		if (num[mid] > a) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l - 1;
}


void solve()
{
	n = read(), t = read();
	for (int i = 0; i < n; i++) {
		num[i] = read();
	}
	num[n] = INF;
	int q = 0;
	while (t--) {
		
		q = read();
		
//		binary();
		ans_l = binary0(q), ans_r = binary1(q);
		if (num[ans_l] != q) {
			ans_l = ans_r = -1;
		}
		cout << ans_l << ' ' << ans_r << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

