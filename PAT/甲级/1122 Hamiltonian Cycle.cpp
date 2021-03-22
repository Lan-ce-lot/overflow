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
int t, n, m, q, flag = 0;
int G[1005][1005], a[maxn];
bool vis[1005][1005];
int path[maxn];
set<int> S;
void dfs() {
	
}
void solve()
{
	n = read(), m = read(); 
	for (int i = 0; i < m; i++) {
		int a = read(), b = read();
		G[a][b] = G[b][a] = 1;
	}
	q = read();
	for (int i = 0; i < q; i++) {
		flag = 0;
		S.clear();
		t = read();
		for (int j = 0; j < t; j++) {
			a[j] = read();
		} 
		if (a[0] != a[t - 1] || t != n + 1) {
			flag = 1;
//			puts("NO");
//			return;
		} else {
			int tmp = a[0];
			for (int j = 1; j < t; j++) {
				if (!G[tmp][a[j]]) {
//					puts("NO");
					flag = 1;
					break;
				} else {
					tmp = a[j];
					S.insert(tmp);
				}
			}
		}
		if (S.size() == n && flag == 0) {
			puts("YES");
		} else if (flag == 0 || S.size() != n){
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

