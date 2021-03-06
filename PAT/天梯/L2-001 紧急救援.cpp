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
#define x first
#define y second 
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
int t, n, m, s, d;


void bfs() {
	queue<PII> Q;
	Q.push({s, 0});
	
	while (Q.size()) {
		PII top = Q.front();
		
		for (int i = 0; i ; i++) {
			
		}
		
	}
	
	
}
int saveteam[505]
int mm[505][505];
int dis[maxn];
bool vis[maxn];
void dj() {
	
	memset(dis, 0x3f3f3f3f, sizeof dis);
	dis[s] = 1;
	for (int i = 0; i < n - 1; i ++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (t == -1 || dis[t] > dis[j])) {
				t = j;
			}	
		}
		
		for ()
//		for (int j = 1; j <= n; j++) {
//			dis[j] = min(dis[j], dis[t] + );
//		}
		
		
	}
}

void solve()
{
	n = read(), m = read(), s = read(), d = read();
	for (int i = 1; i <= n; i++) {
		
	} 
	for (int i = 0; i < n; i++) {
		
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

