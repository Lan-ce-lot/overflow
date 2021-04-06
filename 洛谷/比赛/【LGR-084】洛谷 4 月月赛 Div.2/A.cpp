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
string s;
int sum[maxn];
int coun[26][maxn];
void solve()
{
	cin >> n;
	cin >> s;
	reverse(s.begin(), s.end());
	s = ' ' + s;
	int ans1 = INF, ans2 = INF;
	for (int i = 1; i <= n; i++) {
		int c = s[i] - 'a';
		for (int j = 25; j >= 0; j--) {
			coun[j][i] = coun[j][i - 1];
			if (j == c) coun[j][i] = coun[j][i - 1] + 1;
		}
	}
	// a  c b
	// b  c a
	for (int i = 1; i <= n; i++) {
		int c = s[i] - 'a', sum = 0;
		for (int j = c + 1; j < 26; j++)
			sum += coun[j][i];
		
		if (sum > 0) {
			ans1 = i;break;
		}
	}
	if (ans1 > n) {
		puts("-1");return ;
	}
	for (int i = 1; i < ans1; i++) {
		if (s[i] > s[ans1]) {
			ans2 = i;
			break;
		}
	}

	if (ans1 != INF && ans2 != INF)
		cout << n - ans1 + 1 << ' ' << n - ans2 + 1 << endl;
	else
		puts("-1");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

