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
//	scanf("%lld%lld%lld", &a, &b, &c);

	
	
	ll a = read(), b = read(), c = read();
	ll n; 
	if (c > abs(a - b))
		n = max(a, b) + (c - abs(a - b)) / 2;
	else
		n = min(a, b) + c;
//	ll tem = 0;
//	if (a > b) {
//		if (b + c >= a) {
//			tem = (a + b + c) / 2;
////			debug(tem);
////			printf("%lld\n", (1 + int(sqrt(1 + 8 * tem))) / 2);
//			
//		} else {
//			tem = b + c;
////			printf("%lld\n", (1 + sqrt(1 + 8 * tem)) / 2);
//		}
//	} else {
//		if (a + c >= b) {
//			tem = (a + b + c)/ 2;
////			printf("%lld\n", (1 + sqrt(1 + 8 * tem)) / 2);
//		} else {
//			tem = a + c;
////			printf("%lld\n", (1 + sqrt(1 + 8 * tem)) / 2);
//		}
//	}
	printf("%lld\n", (ll)(sqrt(1 + 8 * n) - 1) / 2);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

