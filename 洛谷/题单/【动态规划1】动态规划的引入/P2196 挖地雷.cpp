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
int a[maxn];
int dp[maxn];
vector<int> G[100];
//int G[100][100];
bool vis[100];
string ans_str = "";
int ans = -INF;
void dfs(int star, int tem, string str) {
	
	if (ans < tem) {
		ans_str = str;
		ans = tem;
	}
	for (int i = 0; i < G[star].size(); i++) {
		int tt = G[star][i];
		if (vis[tt] == 1) continue;
		vis[tt] = 1;
		char c[5];
		sprintf(c, "%d", tt);
		dfs(tt, tem + a[tt], str + " " + c);
		vis[tt] = 0;
	}
//	cout << star << ' ' << tem << endl; 
//	cout << str << endl;
}

void solve()
{
	n = read();
	for (int i = 1 ;i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int tem = read();
			if (tem == 1) {
				G[i].push_back(j);
//				G[j].push_back(i);
			} 
		}
	}
//	cout << char('0' + 1);
	
	
//	tem = tem + char('0' + 1);
//	cout << tem;
//	vis[1] = 1;
//	dfs(1, a[1], tem + char('0' + 1));
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;string tem = "";
		char c[6]; 
		sprintf(c, "%d", i);
		dfs(i, a[i], c);
		vis[i] = 0;
	}
	cout << ans_str << endl;
	cout << ans << endl;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

