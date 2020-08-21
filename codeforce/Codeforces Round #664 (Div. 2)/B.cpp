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
int t, n, m, sx, sy, all;
bool vis[1000][1000];
bool test(int x, int y) {
	return !vis[x][y] && x > 0 && x <= n && y > 0 && y <= m;
}
//vector<PII> ans;
string ans = "";
int flag = 0;
void dfs(int x, int y, int con, string ss) {
	if (flag == 1) {
		return;
	}
	if (con >= all) {
		ans = ss;
		flag = 1;
		return;
	}
	
//	for (int i = 0; i <) {
//		
//	}
}

void solve()
{
	ans.clear();
	n = read(), m = read(), sx = read(), sy = read();
	all = n * m;
	// s
	int i, j = sx;
	for (i = sy; i > 0; i--) {
		printf("%d %d\n", sx, i); 
	}
	for (i = sy + 1; i <= m; i++) {
		printf("%d %d\n", sx, i); 
	}
	for (j = sx - 1; j > 0; j--) {
		int temx = abs(sx - j);
		if (temx % 2 == 1) {
			i--;
			while (i > 0) {
				printf("%d %d\n", j, i);
				i--;
			}
		} else {
			i++; 
			while (i <= m) {
				printf("%d %d\n", j, i);
				i++;
			}			
		}
	}
	// x
	for (j = sx + 1; j <= n; j++) {
		int temx = abs(sx - j);
		if (i > m) {
			temx = 1;
		} else {
			temx = 0;
		}
		if (temx % 2 == 1) {
			i--;
			while (i > 0) {
				printf("%d %d\n", j, i);
				i--;
			}
		} else {
			i++; 
			while (i <= m) {
				printf("%d %d\n", j, i);
				i++;
			}			
		}
	}	
//	dfs(sx, sy, 1);
	
	
//	for (auto it : ans) {
//		cout << ans.first << ' ' ans.second << endl;
//	}
//	puts("");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

