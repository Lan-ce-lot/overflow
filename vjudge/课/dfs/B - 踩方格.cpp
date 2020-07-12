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
bool vis[50][50];// 25 25
ll dir[3][2] = {0, 1, 0, -1, 1, 0}, sum = 0;// r l d
map<int, string> M;

void dfs(int x, int y, int s, string str, int n) {
    if (vis[x][y]) return;
    if (s == n) {sum++;return;}


    vis[x][y] = 1;
    for (int i = 0; i < 3; i++) dfs(x + dir[i][0], y + dir[i][1], s + 1, str + M[i], n);
    vis[x][y] = 0;
}
int ans[100] = {1,
3,
7,
17,
41,
99,
239,
577,
1393,
3363,
8119,
19601,
47321,
114243,
275807,
665857};
void solve()
{
    M[0] = "r";
    M[1] = "l";
    M[2] = "d";
    cin >> n;
    cout << ans[n] << endl;
////    dfs(25, 25, 0, "");
//for (int i = 0; i < 21; i++) {
//        memset(vis, 0, sizeof vis);
//        sum = 0;
//    dfs(25, 25, 0, "", i);
//    cout << sum << ',' <<endl;
//}

}
// 矩阵边界在无穷远处
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

