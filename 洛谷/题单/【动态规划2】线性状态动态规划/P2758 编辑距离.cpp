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
int t, n, dp[2005][2005];

void solve()
{
	string str1, str2;
	cin >> str1>> str2;
//	cout << str1.size() << str2.size() << endl;
	int len1 = str1.size(), len2 = str2.size();
	for (int i = 1; i <= len1; i++) dp[i][0] = i;
	for (int i = 1; i <= len2; i++) dp[0][i] = i;
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << dp[len1][len2] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

