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
int po[maxn], in[maxn], maxu = 0;
int tree[maxn];
vector<int> ans[1005];
struct node {
	int l, r;
}T[maxn];
struct qq {
	int ind, dep;
};
void build(int in_l, int in_r, int po_l, int po_r, int fa, int flag, int dep) {
	if (in_l > in_r) {
		return;
	}
	if (flag) {
		ans[dep].push_back(po[po_r]);
		T[fa].r = po[po_r];
	} else {
		ans[dep].push_back(po[po_r]);
		T[fa].l = po[po_r];
	}
	int i = -1;
	while (in[++i] != po[po_r]);
	build(in_l, i - 1, po_l, po_l + i - 1 - in_l, po[po_r], 0, dep + 1);
	build(i + 1, in_r, po_r - 1 - in_r + i + 1, po_r - 1, po[po_r], 1, dep + 1);
}

void solve()
{
	n = read();
	memset(tree, -1, sizeof tree);
	for (int i = 0; i < n; i++) {
		in[i] = read();
	}
	for (int i = 0; i < n; i++) {
		po[i] = read();
	}
	int root = po[n];
	build(0, n - 1, 0, n - 1, 0, 0, 0);
//	bfs(root);
	printf("%d", ans[0][0]);
	for (int i = 1; i < 31; i++) {
		if (i % 2) {
			for (int j = 0; j < ans[i].size(); j++) {
				printf(" %d", ans[i][j]);
			}
		} else {
			for (int j = ans[i].size() - 1; j >= 0; j--) {
				printf(" %d", ans[i][j]);
			}
		}
	}puts("");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

