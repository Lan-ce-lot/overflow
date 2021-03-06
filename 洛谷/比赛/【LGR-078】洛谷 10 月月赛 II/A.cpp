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



bool vis[1000][1000];
int res = 0;vector<int> G[maxn];
void dfs(int now, int step) {res = max(step, res);
	if (step >= n + (n - 3) * n / 2) {
		
		return;
	}
	
	// n + (n - 3) * n / 2
	for (int i = 0; i < G[now].size(); i++) {
		int to = G[now][i];
		if (!vis[to][now]) {
			vis[to][now] = vis[now][to] = 1;
			dfs(to, step + 1);
			vis[to][now] = vis[now][to] = 0;
		}
	}
}


void solve()
{
	t = read();
	while (t--) {
//		int res = 0;
		res = 0;
		n = read();
		ll tp = (n - 1) / 2;
		if (n & 1)
			printf("%lld\n", tp * (tp - 1) * 2 + tp * 3);
		else
			printf("%lld\n", tp * (tp + 1) * 2 + 1);		
		
	} 
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

