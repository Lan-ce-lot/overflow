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
int p[maxn], cl[maxn];
struct node {
	int v;
	node *l, *r;
};
node * build(node *root, int v) {
	if (root == NULL) {
		root = new node();
		root->v = v;
		root->l = root->r = NULL;
	} else if (abs(v) <= abs(root->v))
		root->l = build(root->l, v);
	else 
		root->r = build(root->r, v);
	return root;
}
bool j1(node *root) {
	if (root == NULL) return 1;
	if (root->v < 0) {
		if (root->l != NULL && root->l->v < 0) return 0;
		if (root->r != NULL && root->r->v < 0) return 0;
	}
	return j1(root->l) && j1(root->r);
}
int get(node *root) {
	if (root == NULL) return 0;
	int l = get(root->l);
	int r = get(root->r);
	return root->v > 0 ? max(l, r) + 1 : max(l, r);
}
bool j2(node *root) {
	if (root == NULL) return 1;
	int l = get(root->l);
	int r = get(root->r);
	if (l != r) return 0;
	return j2(root->l) && j2(root->r); 
}
void solve()
{
	t = read();
	while (t--) {
		n = read();
		node *root = NULL;
		for (int i = 0; i < n; i++) {
			p[i] = read();
			root = build(root, p[i]);
		}
		if (p[0] < 0 || j1(root) == 0 || j2(root) == 0) puts("No");
		else puts("Yes");
		
//		for (int i = 1; i <= n; i++) cout << T[i].l << T[i].r << ' ';
//		dfs(1);
		
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

