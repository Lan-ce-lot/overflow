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
#include <unordered_map>
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
string tem;

int pa[maxn];
int find(int x) {
	if (x == pa[x]) return x;
	else return pa[x] = find(pa[x]);
}
void unite(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) {
		pa[y] = x;
	}
}
string fa;
unordered_map<string, bool> vis;
unordered_map<string, int> M;
unordered_map<int, string> R;
void solve()
{
	for (int i = 0; i <= 500000; i++) pa[i] = i;
	int tot = 1;
	while (cin >> tem) {
//		debug(tem.substr(1, tem.size()));
		string son = tem.substr(1, tem.size());
		if (tem[0] == '$') return ;
		if (!vis[son]) {
			R[tot] = son;

			M[son] = tot++;
			vis[son] = 1;
		}
		if (tem[0] == '#') {
			fa = son;
			
		}
		if (tem[0] == '+') {
			unite(M[fa], M[son]);
		}
		if (tem[0] == '?') {
			int ff = find(M[son]);
//			debug(ff);
//			debug(R[ff]);
			cout << son << ' ' << R[ff] << '\n';
//			printf("%s %s\n", tem + 1, R[ff]);
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

