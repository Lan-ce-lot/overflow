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
char str[100];
int dp[1000][1000];//   ��i����ĸ����kmp��j��״̬ 
int ne[1000];
void solve()
{
	cin >> n;
	cin >> str + 1;
	int m = strlen(str + 1);
	for (int i = 2, j = 0; i <= m; i++) {
		while (j && str[i] != str[j + 1]) j = ne[j];
		if (str[i] == str[j + 1]) j++;
		ne[i] = j;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (char k = 'a'; k <= 'z'; k++) {
				int u = j;
				while (u && str[u + 1] != k) u = ne[u];
				if (str[u + 1] == k) u++;
				if (u < m) dp[i + 1][u] = (dp[i + 1][u] + dp[i][j]) % mod;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		res = (res + dp[n][i]) % mod;
	}
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

