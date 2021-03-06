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
set<ll> S;
ll a[maxn];
ll tmp[maxn];
ll ca[maxn];
ll vis[maxn];

void solve()
{
	t = read();
	while (t--) {
		map<ll, int> M;
		n = read();
		S.clear();
		int flag = 0;
		for (int i = 0; i < n * 2; i++) {
			a[i] = read();
			M[a[i]]++;
			S.insert(a[i]);
			if (a[i] & 1) {
				flag = 1;
			}
		}
		for (int i = 0; i < n * 2; i++) {
			if (M[a[i]] != 2) {
				flag = 1;
			}
		}
		if (S.size() != n) {
			flag = 1;
		} 
		int i = 0;
		for (auto it : S) {
			tmp[i++] = it;
		}
		ll to = 0;
		for (int i = 0; i < n - 1; i++) {
			ca[i] = (tmp[i + 1] - tmp[i]) / 2 / (i + 1);
		}
		to = tmp[n - 1] / n / 2;
		for (int i = n - 1; i > 0; i--) {
			to = to - ca[i - 1];
			if (to <= 0) {
				flag = 1;
			}
//			cout << tmp[i] << endl;
		}
		if (flag) {
			puts("NO");
		} else {
			puts("YES");
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

