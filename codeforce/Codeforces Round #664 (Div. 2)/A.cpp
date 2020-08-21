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
int t, n, a, b, c, d;

void solve()
{
	t = read();
	while (t--) {
		a = read(), b = read(), c = read(), d = read();
		ll sum = a + b + c + d;
		ll con = (a % 2) + (b % 2) + (c % 2) + (d % 2);
		
		if (sum % 2 == 0) {
			if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 0) {
				puts("YES");
			} else {
				if (a % 2 == 1 && b % 2 == 1 && c % 2 == 1 && d % 2 == 1) {
					puts("YES");
				} else {
					puts("NO");
				}
				
			}
		} else {
			if (a == 0 || b == 0 || c == 0) {
				if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 1) {
					puts("YES");
				} else if (a % 2 == 1 && b % 2 == 1 && c % 2 == 1 && d % 2 == 0) {
					puts("YES");
				} else if (con == 1){
					puts("YES");
				} else {
					puts("NO");
				}
			} else {
				if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0 && d % 2 == 1) {
					puts("YES");
				} else if (a % 2 == 1 && b % 2 == 1 && c % 2 == 1 && d % 2 == 0) {
					puts("YES");
				} else if (con == 3 && d % 2 == 1) {
					puts("YES");
				} else if (con == 1){
					puts("YES");
				} else {
					puts("NO");
				}			
			}
		}
	} 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

