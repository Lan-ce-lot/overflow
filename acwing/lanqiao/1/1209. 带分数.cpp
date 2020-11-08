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
int t, n, num[maxn], ans = 0;
bool vis[maxn];

int calc(int l, int r) {
	int res = 0;
	for (int i = l; i <= r; i++) {
		res = res * 10 + num[i];
	}
	return res;
}

void dfs(int u) {
	
	if (u == 9) {
		for (int i = 0; i < 7; i++) {
			for (int j = i + 1; j < 8; j++) {
				int a = calc(0, i);
				int b = calc(i + 1, j);
				int c = calc(j + 1, 8);
				if (n * c == c * a + b) {
					ans++;
				}
			}
		}
		return;
	}
	
	for (int i = 1; i <= 9; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			num[u] = i;
			dfs(u + 1);
//			num[u] = 0;
			vis[i] = 0;
		}	
	}
	
}



void solve()
{
	n = read();
	
	
	dfs(0);
	
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

