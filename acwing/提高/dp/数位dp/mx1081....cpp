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
int f[100][100];

int X, Y, K, B;
void init() {
	for (int i = 0; i <= 35; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				f[i][j] = 1;
			} else {
				f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
			}
		}
	}
}


int dp(int n) {
	if (n == 0) return 0; 
	int res = 0, last = 0;
	vector<int> num;
	while (n) {
		num.push_back(n % B), n /= B;
	}
	
	for (int i = num.size() - 1; i >= 0; i--) {
		int a = num[i];
		if (a) {				
			res += f[i][K - last];
			if (a > 1) { // zuo
				if (K - last - 1 >= 0) {
					res += f[i][K - last - 1];
					break;
				}
			} else {
				last++;
				if (last > K) {
					break;
				}
			}
		} 
		if (i == 0 && last == K) {
			res++;
		}
	}	
	
	return res;
}


void solve()
{
	X = read(), Y = read(), K = read(), B = read();
	
	init();
	cout << dp(Y) - dp(X - 1) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

