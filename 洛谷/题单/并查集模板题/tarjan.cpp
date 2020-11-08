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
const int INF = 0x3f3f3f3f; //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;
//sacnf("%lf") printf("%f")
ll read()
{
	ll x = 0, f = 1;
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
bool vis[maxn];
int dfn[maxn], low[maxn], dfs_num, size[maxn];
int color[maxn], col_num = 0;
int h[maxn], ne[maxn], e[maxn], tot = 1;
void add(int a, int b) {
	e[tot] = b, ne[tot] = h[a], h[a] = tot ++; 
}

stack<int> S;
void Tarjan(int x)
{
	int tem;
	low[x] = dfn[x] = ++ dfs_num;
	vis[x] = 1;// 是否在栈中 
	S.push(x);// 进栈
	for (int i = h[x]; i; i = ne[i]) {
		int to = e[i];
		if (!dfn[to]) {
			Tarjan(to);
			low[x] = min(low[x], low[to]);
		} else if (vis[to]) {
			low[x] = min(low[x], dfn[to]);
		}
	} 
	if (dfn[x] == low[x]) {//构成强连通分量
		
		col_num++;//染色
		
		do{
			tem=S.top();S.pop();vis[tem] = 0;
			color[tem] = col_num;
		} while (tem!=x);
	}
}
int ru[maxn];
void solve()
{
	int ans = 0;
	n = read();
	
	for (int i = 1; i <= n; i++) {
		while (true) {
			int a = read();
//			fa[a] = 1;
			if (a == 0) break;
			else {
//				unite(i, a);
				add(i, a);
			}
		}
	}
//	debug(2);
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		{
			Tarjan(i);
		}
	}
//	debug(1);
	for(int i=1;i<=n;i++)
	{
		for(int j=h[i];j;j = ne[j])
		{
			int next=e[j];
			if(color[i]!=color[next])
			{
//				cout << i << ' ' << j << ' ' << color[i] << ' ' << color[next] << ' ' << endl;
				ru[color[next]]++;
			}
		}
	}
	for(int i=1;i<=col_num;i++)
	{
//		debug(col_num);
		if(!ru[i]){
			ans++;
		}
			
	}
	cout<<ans << endl;
}

int main()
{

	//    freopen("F:/Overflow/in.txt","r",stdin);
	//    ios::sync_with_stdio(false);
	solve();
	return 0;
}
