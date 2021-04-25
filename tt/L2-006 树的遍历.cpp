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
int t, n, a[maxn];
int po[maxn], in[maxn];
vector<int> V[55];
int get(int x) {
	int res = 0;
	while (x) x >>= 1, res++;
	return res;
}
int all_d = 0;
void dfs(int pl, int pr, int il, int ir, int u) {
	if (pl > pr) {
		return;
	}
	int root = il;
	
	while (in[root] != po[pr]) root++;
	int de = get(u);
	all_d = max(all_d, de);
	V[de].push_back(po[pr]);
	dfs(pl, pl + root - 1 - il, il, root - 1, u << 1);
	dfs(pl + root - il, pr - 1, root + 1, ir, u << 1 | 1);
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> po[i];
	
	for (int i = 1; i <= n; i++)
		cin >> in[i];
	
	dfs(1, n, 1, n, 1);
	for (int i = 1; i <= all_d; i++) {
		for (int j = 0; j < V[i].size(); j++) {
			cout << V[i][j];
			if (i == all_d && j == V[i].size() - 1) {
				puts("");
			} else {
				cout << ' ';
			}
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

