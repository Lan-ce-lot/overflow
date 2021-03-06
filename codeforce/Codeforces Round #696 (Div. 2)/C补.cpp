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
int t, n, a[maxn], flag = 0;
multiset<int> S;
vector<int> ANS;
void solve()
{
	t = read();
	while (t--) {
		flag = 0;
		n = read();
		for (int i = 0; i < n * 2; i++) {
			a[i] = read();
		}
		sort(a, a + 2 * n);
		for (int i = 0; i < n * 2 - 1; i++) {
			int x = a[i] + a[2 * n - 1];
			S.clear();
			ANS.clear();
			for (int j = 0; j < 2 * n; j++) {
				S.insert(a[j]);
			}

			for (int j = 0; j < n; j++) {
				auto itend = S.end();
				itend--;
				int y = x - *itend;
				S.erase(itend);
				auto it2 = S.find(y);
				if (it2 == S.end()) {
					break;
				} else {
					ANS.push_back(x - y);
					ANS.push_back(y);
					x = max(y, x - y);
					S.erase(it2);
				}
			}
			
			
			if (ANS.size() == n * 2) {
				puts("YES");
				cout << ANS[0] + ANS[1] << endl;
				for (int i = 0; i < ANS.size(); i+=2) {
					cout << ANS[i] << ' ' << ANS[i + 1] << endl;
				}
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			puts("NO");
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

