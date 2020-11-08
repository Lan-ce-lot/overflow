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

bool check(string str) {
	int len = str.size();
	for (int i = 0; i < str.size(); i++) {
		if (str[(i + len + 1) % len] != str[(i + len - 1) % len]) {
			return 0;
		}
	}
	return 1;
}
int num[10];
void solve()
{
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		memset(num, 0, sizeof num);
		int len = str.size();
		if (check(str)) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < len; i++) {
			num[str[i] - '0']++;
		}
		int min_n = *max_element(num, num + 10);
		int ans = min(len - 2, len - min_n);
		
		for (int i = 0; i < 10; i++) {
			char c_i = char(i + '0');
			for (int j = 0; j < 10; j++) {
				char c_j = char(j + '0');
				if (i != j) {
					int temp = 0;
//					int k = 0;
					for (int k = 0; k < len;) {
						int flag = 0;
						while (str[k] != c_i) {
							k++;
							if (k >= len) {
								flag = 1;
								break;
							}
						}
						while (str[k] != c_j) {
							k++;
							if (k >= len) {
								flag = 1;
								break;
							}
						}
						if (k >= len) {
							break;
						} else {
							temp++;
						}
					}
//					cout << i << ' ' << j << ' ' << temp << endl;
//					debug(temp);
					ans = min(ans, len - 2 * temp);
				}
			}
		}
		
		cout << ans << endl;
	}
}
/*
100
1231425162718920121
1212121212
1231421

*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

