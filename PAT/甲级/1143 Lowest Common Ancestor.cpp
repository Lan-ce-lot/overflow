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
#include <unordered_set>
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
int t, n, tr[maxn];
unordered_set<int> S;
void solve()
{
	t = read(), n = read();
	for (int i = 1; i <= n; i++) tr[i] = read(), S.insert(tr[i]);
	while (t--) {
		int a = read(), b = read();
		if (!S.count(a) && !S.count(b)) {
			printf("ERROR: %d and %d are not found.\n", a, b);continue;
		}
		if (!S.count(a)) {
			printf("ERROR: %d is not found.\n", a);continue;
		}
		if (!S.count(b)) {
			printf("ERROR: %d is not found.\n", b);continue;
		}
//		if (a > b) swap(a, b);
		for (int i = 1; i <= n; i++) {
			if (tr[i] <= a && tr[i] >= b || tr[i] >= a && tr[i] <= b) {
				if (tr[i] == a) {
					printf("%d is an ancestor of %d.\n", a, b);break;
				} else if (tr[i] == b) {
					printf("%d is an ancestor of %d.\n", b, a);break;
				} else {
					printf("LCA of %d and %d is %d.\n", a, b, tr[i]);break;
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

