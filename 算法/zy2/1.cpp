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
int N = 1e5;
int n, t[maxn], d[maxn], i;
//int M1[N], M2[N] = {}, M3[N], M4[N], M5[N], M6[N];
/*
1 [1, 10] 9 ------------ 1000000
2 [0, 16] 16     ------- 100000
3 [1, 100] 100   ------- 1000
4 [1, 1000] 1000 ------- 100
5 [2, 1024] 1024 ------- 20
6 [1, 3628800] 3628800 - 10
*/
void solve()
{
	
	while (cin >> n, n) {
		for (i = 0; i < n; i++) cin >> d[i];
		for (i = 0; i < n; i++) cin >> t[i];
		sort(t, t + n);
		sort(d, d + n);
		for (i = 0; i < n; i++) cout << d[i] << ' ';puts("");
		for (i = 0; i < n; i++) cout << t[i] << ' ';puts("");
		int a = t[n - 1] - t[0];
		int b = d[n - 1] - d[0];
		debug(a);debug(b);
		// a = b * k
		if (abs(a-b) <= 20) {
			cout<<"1\n";
		} else if (a > b * 2 && a < b * 9) {
			cout<<"2\n";
		} else if (1) {
			
		}
	}
}
/*
4
8 10 11 9
0 375 4218 31
6
17 20 24 19 22 25
16 110 1703 47 406 3468
5
359999 431998 518397 300000 746491
31 47 47 31 78
0

第二行：k个整数，为运行规模，整数（<1000001），每个数据之间有一个空格

第三行：k个整数，为运行时间，整数（<100000），每个数据之间有一个空格
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

