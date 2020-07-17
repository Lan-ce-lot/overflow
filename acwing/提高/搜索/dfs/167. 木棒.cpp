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
int t, n, flag = 0;
int sum, len, a[100];
bool vis[100];
vector<int> G[100];

bool dfs(int u, int s, int star) {
	if (u * len == sum) return 1;
	if (s == len) return dfs(u +1, 0, 0);
	
	// 3-1 i从star开始枚举 
	for (int i = star; i < n; i++) {
		if (vis[i]) continue;
		if (s + a[i] > len) continue; // 可行性剪枝 
		vis[i] = 1;
		if (dfs(u, s + a[i], i + 1)) return 1;
		
		vis[i] = 0;
		
		if (!s || s + a[i] == len) return 0;
		// 3-2 排除长度一样的 
		int j = i;
		while (j < n && a[j] == a[i]) {
			j++;
		}
		i = j - 1;
	}
	return 0;
}

void solve()
{
	while (cin >> n, n) {
		memset(vis, 0, sizeof vis);
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + n, greater<int> ());
		len = 1;
		while (1) {
			if (sum % len == 0 && dfs(0, 0, 0)) {
				cout << len << endl;
				break;
			}
			len++;
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

