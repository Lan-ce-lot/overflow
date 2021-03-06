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
const int maxn = 105;
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
int yh[maxn][maxn];
void solve()
{
	yh[1][1] = 1;
	
	for (int i = 2; i < maxn; i++) {
		for (int j = 1; j <= i; j++) {
			yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
		}
	}
//	for (int i = 1; i < maxn; i++) {
//		for (int j = 1; j <= i; j++) {
//			cout << yh[i][j] << ' ';
//		}
//		puts("");
//	}	
	n = read();
	map<int, string> M{
	{1, "1.00"}, {2, "0.50"}, {3, "0.25"}, {4, "0.13"}, {5, "0.06"}, {6, "0.03"}, {7, "0.02"}, {8, "0.01"}
	};
	if (n < 9) {
		return M[n];
	} else {
		return "0.00";
	}
	
}
/*
1.00
0.50
0.25
0.13
0.06
0.03
0.02
0.01

*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

