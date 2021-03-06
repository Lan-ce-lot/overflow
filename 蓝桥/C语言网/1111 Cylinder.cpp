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
const double pi = 3.141592653589793238;
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
double t, a, b, ans = 0, r = 0, h = 0, tem = 0;

void solve()
{
	while (~scanf("%lf %lf", &a, &b)) {
		if (a == 0 && b == 0) {
			return;
		}
		if (a > b) {
			swap(a, b);
		}
		/**
		
		r = a / 2 / pi
		h = b - 2 * r
		
		b - a >= pi * a
		r = a / 2
		h = a
		
		*/
//		if (b - a >= pi * a) {
//			r = a / 2;
//			h = a;
//		} else if (b - a < pi * a && b >= a / pi + a) {
//			r = b / (2 * pi + 2);
//			h = a;
//		} else {
//			r = a / 2 / pi;
//			h = b - 2 * r;	
//		}
		r = a / 2 / pi;
		double res1 = pi * r * r * (b - 2 * r);
		
		if (b - a >= pi * a) {
			r = a / 2;
			h = a;
		} else if (b - a < pi * a && b >= a / pi + a) {
			r = b / (2 * pi + 2);
			h = a;
		} else {
			r = a / 2 / pi;
			h = b - 2 * r;	
		}
		ans = pi * r * r * h;
		
		
		printf("%.3f\n", max(ans, res1));
	} 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

