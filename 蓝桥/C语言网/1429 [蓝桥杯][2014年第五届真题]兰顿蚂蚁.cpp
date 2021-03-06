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
int maze[1005][1005];
int x, y, k;
char s;
//若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；
//若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。
string dir = "ULDR";// 左+1，右-1 
int dir_d[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
void solve()
{
	n = read(), m = read();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j< m; j++) {
			scanf("%d", &maze[i][j]);
		}
	}
	scanf("%d %d %c %d", &x, &y, &s, &k);
	int pos = dir.find(s);
//	debug(pos);
	for (int i = 0; i < k; i++) {
		
		if (maze[x][y]) {
			pos = (pos + 4 - 1) % 4;
			maze[x][y] = !maze[x][y];
			x += dir_d[pos][0];
			y += dir_d[pos][1];
			
		} else {
			
			pos = (pos + 4 + 1) % 4;
			maze[x][y] = !maze[x][y];
			x += dir_d[pos][0];
			y += dir_d[pos][1];
		}
		
	} 
	cout << x << ' ' << y << endl;
}

int main()
{
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

