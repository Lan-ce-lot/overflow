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
ll t, n, N, K, ans = 0;
int ma[10][10] = {
	1,2,3,4,5,6,7,8,9,10,
	2,4,5,6,7,8,9,10,11,12,
	3,6,8,9,10,11,12,13,14,15,
	4,8,11,13,14,15,16,17,18,19,
	5,10,13,16,18,19,20,21,22,23,
	6,12,16,19,22,24,25,26,27,28,
	7,14,19,22,25,28,30,31,32,33,
	8,16,21,25,28,31,34,36,37,38,
	9,18,24,29,32,35,38,41,43,44,
	10,20,27,32,36,39,42,45,48,50
};
int tem[10][10];
void solve()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%4d", (i + 1) * (j + 1) - ma[i][j]);
//			cout << (i + 1) * (j + 1) - ma[i][j] << ' ';
		}
		puts("");
	}
	// N / k * (k - 2)
	// N % k - 1
	N = read(), K = read();
	if ( K <= 2){
		ans = (K % mod * N % mod) % mod;
		printf("%lld\n", ans);
	} else if (N <= 1) {
		ans = (K % mod * N % mod) % mod;
		printf("%lld\n", ans);
	} else {
		
		
		printf("%lld\n", ans);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

