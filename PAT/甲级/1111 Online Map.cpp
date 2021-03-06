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
int t, n, m, s, e;
int G[1005][1005], maze_d[1005][1005], maze_t[1005][1005], w[1005];
int dispre[501], dis[1005], Timepre[1005], Time[1005], cnt[1005];
bool st[1005];
vector<int> dispath, Timepath, temppath;


void dfs1(int u) {
	dispath.push_back(u);
	if (u == s) return;
	dfs1(dispre[u]);
}

void dj1(int s) {
	memset(st, 0, sizeof st);
	memset(w, 0x3f, sizeof w);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int t = -1;
		for (int j = 0; j < n; j++) 
			if (!st[j] && (t == -1|| dis[t] > dis[j])) t = j;
		
		for (int j = 0; j < n; j++) {
			if (dis[j] > dis[t] + maze_d[t][j]) {
				dis[j] = dis[t] + maze_d[t][j];
				dispre[j] = t;
				w[j] = maze_t[t][j] + w[t]; 
			} else if (dis[t] + maze_d[t][j] == dis[j] && w[j] > w[t] + maze_t[t][j]) {
				w[j] = w[t] + maze_t[t][j];
				dispre[j] = t;
			}
		}
		st[t] = 1;
	}
}
void dfs2(int u) {
	Timepath.push_back(u);
	if (u == s) return;
	dfs2(Timepre[u]);
}

void dj2(int s) {
	memset(st, 0, sizeof st);
	memset(Time, 0x3f, sizeof Time);
	Time[s] = 0;
	for (int i = 0; i < n; i++) {
		int t = -1;
		for (int j = 0; j < n; j++) 
			if (!st[j] && (t == -1|| Time[t] > Time[j])) t = j;
		
		for (int j = 0; j < n; j++) {
			if (Time[j] > Time[t] + maze_t[t][j]) {
				Time[j] = Time[t] + maze_t[t][j];
				Timepre[j] = t;
				cnt[j] = cnt[t] + 1;
			} else if (Time[t] + maze_t[t][j] == Time[j] && cnt[j] > cnt[t] + 1) {
				cnt[j] = cnt[t] + 1;
				Timepre[j] = t;
			}
		}
		st[t] = 1;
	}
}
void solve()
{
//	debug(0x3f3f3f3f);
	n = read(), m = read();
	memset(maze_d, 0x3f, sizeof maze_d);
	memset(maze_t, 0x3f, sizeof maze_t);
	for (int i = 0; i < m; i++) {
		int V1 = read(), V2 = read(), oneway = read(), length = read(), Time = read();
		if (oneway == 1) {
			maze_d[V1][V2] = length;
			maze_t[V1][V2] = Time;
		} else {
			maze_d[V1][V2] = length;
			maze_t[V1][V2] = Time;
			maze_d[V2][V1] = length;
			maze_t[V2][V1] = Time;
		}
	}
	
	s = read(), e = read();
	for (int i = 0; i < n; i++) {
		dispre[i] = i;
	}
	dj1(s);
	dfs1(e);
	dj2(s);
	dfs2(e);
	printf("Distance = %d", dis[e]);
	if (dispath == Timepath) {
		printf("; Time = %d: ", Time[e]);
	} else {
		printf(": ");
		for (int i = dispath.size() - 1; i >= 0; i--) {
			printf("%d", dispath[i]);
			if (i != 0) printf(" -> ");
		}
		printf("\nTime = %d: ", Time[e]);
	}
	for (int i = Timepath.size() - 1; i >= 0; i--) {
		printf("%d", Timepath[i]);
		if (i != 0) printf(" -> ");
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

