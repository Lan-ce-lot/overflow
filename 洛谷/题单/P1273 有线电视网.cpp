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
int t, n, m;
int h[maxn], ne[maxn], tot = 1;
struct node {
	int to, cost; 
}e[maxn];
void add(int a, int b, int c) {
	e[tot] = {b, c}, ne[tot] = h[a], h[a] = tot++;
}
int ye[maxn], tt[maxn], dp[3010][3010];;
int dfs(int u) {
	if (u > n - m) {
		
		dp[u][1] = ye[u];
		return 1;
	}
	int sum = 0;
	for (int i = h[u]; i; i = ne[i]) {
		int to = e[i].to;
		int v = e[i].cost;
		int tk = dfs(to);
        for (int j=0;j<=sum;j++)tt[j]=dp[u][j];
        for (int j=0;j<=sum;j++)
            for (int k=0;k<=tk;k++)
                dp[u][j+k]=max(dp[u][j+k],tt[j]+dp[to][k]-v);
        sum+=tk;
		
	}
	
	return sum;
}




void solve()
{
	
	n = read(), m = read();
	memset(dp,~0x3f,sizeof(dp));
	for (int i = 1; i <= n - m; i++) {
		t = read();
		while (t--) {
			int b = read(), c = read();
			add(i, b, c); 
//			add(b, i, c);
		}
	}
	int ans = 0;
	for (int i = n - m + 1; i <= n; i++) {
		ye[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
	}
	dfs(1);
	for (int i = m; i > 0; i--) {
		if (dp[1][i] >= 0) {
//			ans = max(ans, i);
			printf("%d",i);break;
		}
	}
	
//	cout <<ans << endl;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

