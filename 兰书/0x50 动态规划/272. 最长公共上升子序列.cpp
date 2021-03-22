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
int t, n, s1[maxn], s2[maxn], dp[3005][3005];

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) s1[i] = read();
	
	for (int j = 1; j <= n; j++) s2[j] = read();
	
	for (int i = 1; i <= n; i++) {
		int maxx = 1;
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];
			if (s1[i] == s2[j]) {
				dp[i][j] = max(maxx, dp[i][j]);
			}
			if (s1[i] > s2[j]) {
				maxx = max(maxx, dp[i - 1][j] + 1);
			}
		}
	} 
	cout << *max_element(dp[n] + 1, dp[n] + 1 + n) << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

