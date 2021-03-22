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
int t, n, tree[maxn], po[maxn], flag_l = 0, flag_u = 0, ind = 1;
void pos(int u) {
	if (u > n) {
		return;
	}
	if (u != 1) {
		if (tree[u] >= tree[u / 2]) {
			flag_l++;
		}
		if (tree[u] <= tree[u / 2]) {
			flag_u ++ ;
		}
	}
	pos(u << 1);
	pos(u << 1 | 1);
	po[ind++] = tree[u];
}
void solve()
{
	t = read(), n = read();
	while (t--) {
		memset(tree, 0, sizeof tree);
		flag_l = flag_u = 0, ind = 1;
		for (int i = 1; i <= n; i++) {
			tree[i] = read();
		}
		pos(1);
//		debug(flag_l);
//		debug(flag_u);
		if (flag_u == n - 1) {
			puts("Max Heap");
		} else if (flag_l == n - 1) {
			puts("Min Heap");
		} else {
			puts("Not Heap");
		}
		for (int i = 1; i < ind; i++) {
			printf("%d%s", po[i], i == ind - 1? "\n":" ");
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

