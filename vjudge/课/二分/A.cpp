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
double t, n, L, C, L1, ans;
/*
长度:L
加热:n
L' = (1 + n * C) * L
弦 -> 弧
L, n, C
求距离 .3 
*/

double bin(double l0, double l1)
{
	double l = 0, r = l0 / 2.0;
	while (r - l > eps)
	{
		double mid = (l + r) / 2.0;
		double r1 = (mid * mid * 4 + l0 * l0) / (8 * mid);
		if (2 * r1 * asin(l0 / (2 * r1)) > l1)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	return l;
}

void solve()
{
	while (cin >> L >> n >> C)
	{
		if (L == -1 && n == -1 && C == -1)
		{
			return;
		}
		L1 = (1 + n * C) * L;
//		debug(L1);
		
		
		printf("%.3f\n", bin(L, L1));
		
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

