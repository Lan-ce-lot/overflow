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
ll a[maxn];
int p[maxn], cnt[maxn], last[maxn];
int find(int x) {
	if (p[x] == x) {
		return x;
	} else {
		return p[x] = find(p[x]);
	}
}
void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		p[y] = x;
		cnt[x] += cnt[y];
	}
}
void solve()
{
	while (cin >> n) {
		for (int i = 0; i <= n; i++) p[i] = i, cnt[i] = 1;
		memset(last, 0, sizeof last);
		for (int i = 1; i <= n; i++) {
			scanf("%d:", &t);
			
			int tmp = 0, res = 0;
			for (int j = 0; j < t; j++) {
				tmp = read();
				if (!last[tmp])last[tmp] = i;
				Union(i, find(last[tmp]));
			}
		}
		int ans = 0;
		vector<int> num;
		for (int i = 1; i <= n; i++) {
			if (p[i] == i) ans++, num.push_back(cnt[i]);
		}
		printf("%d\n", ans);
		sort(num.begin(), num.end(), greater<int>());
		for (int i = 0; i < num.size(); i++) {
			printf("%d%s", num[i], num.size() - 1 == i? "\n":" ");
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

