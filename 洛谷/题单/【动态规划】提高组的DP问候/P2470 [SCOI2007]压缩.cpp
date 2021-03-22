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
int t, n, dp[1005][1005][2], e[maxn];
string s;
bool check(int l, int r, int len) {
	if (len & 1) return 0;
	len >>= 1;
	for (int i = l; i <= r; i++) {
		if (s[i] != s[(i - l) % len + l]) {
			return 0;
		}
	}
	return 1;
}
bool check(int l,int r){
	if((r-l+1)&1)return 0;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++)
		if(s[i]!=s[i+mid-l+1])return 0;
	return 1;
}//判断前一半是否和后一半相等
void solve()
{
	
	cin >> s;
	n = s.size();
	s = ' ' + s;
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			dp[i][j][0] = dp[i][j][1] = j - i + 1;
//	debug(1);
	for (int len = 2; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (check(l, r, len)) 
				dp[l][r][0] = min(dp[l][(l + r) / 2][0] + 1, dp[l][r][0]);
			for (int k = 1; k < r; k++)
				dp[l][r][0] = min(dp[l][r][0], dp[l][k][0] + r - k);
			for (int k = 1; k < r; k++)
				dp[l][r][1] = min(dp[l][r][1], min(dp[l][k][0], dp[l][k][1]) + 
				min(dp[k + 1][r][0], dp[k + 1][r][1]) + 1);
		}
	}
	cout << min(dp[1][n][1], dp[1][n][0]);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

