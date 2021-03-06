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
/*
3 + 1 
***
 *
***

1 + 3 + 5
*****
 ***
  *
 ***
*****

1 + 3 + 5 + 7
*******
 *****
  ***
   *
  ***
 *****
*******

*/
int n, sum = 0;
char c;
void solve()
{
	while (~scanf("%d %c", &n, &c)) {
		sum = 0;
		int l = 1, r = 10005, mid = l + r + 1 >> 1;
		while (l < r) {
			mid = l + r + 1 >> 1;
			if (mid * mid * 2 - 1 <= n) {
//				r = mid - 1;
				l = mid;
//				r = mid - 1;
			} else if (mid * mid * 2 - 1 > n) {
//				l = mid;
				r = mid - 1;
			}
		}
		
		
		int lie = l;
//		debug(lie);
		int mx = lie * 2 - 1;
		for (int i = 0; i < lie; i++) {
			for (int j = 0; j < mx; j++) {
				if (i > mx - j - 1) {
					break;
				}
				if (i <= j && i <= mx - j - 1) {
					cout << c;
				} else {
					cout << ' ';
				}
				
			}
			puts("");
		}
		for (int i = lie; i < lie * 2 - 1; i ++) {
			for (int j = 0; j < mx; j++) {
				if (i < j) {
					break;
				}
				if (i >= j && i >= mx - j - 1) {
					cout << c;
				} else {
					cout << ' ';
				}
			}
			puts("");
		}
		// n * n * 2 - 1;
		
		cout << n - lie * lie * 2 + 1 << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

