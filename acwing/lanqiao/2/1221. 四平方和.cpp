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
const int maxn = 2500010;
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

struct node {
	int sum, c, d;
	
}N[maxn];
bool cmp(node a, node b) {
	if (a.sum != b.sum) {
		return a.sum < b.sum;
	} else if (a.c != b.c) {
		return a.c < b.c;
	} else {
		return a.d < b.d;
	}
}
void solve()
{
	n = read();
	int tot = 0;
	for (int i = 0; i * i <= n; i ++) {
		for (int j = i; j * j + i * i <= n; j++) {
			N[tot++] = {i * i + j * j, i, j};
		}
	}
//	debug(tot);
	sort(N, N + tot, cmp);
	for (int i = 0; i * i <= n; i++) {
		for (int j = i; j * j + i * i <= n; j++) {
			int t = n - i * i - j * j;
			int l = 0, r = tot - 1;
			while (l < r) {
				int mid = l + r >> 1;
				if (N[mid].sum >= t) {
					r = mid;
				} else {
					l = mid + 1; 
				}
			}
			if (N[l].sum == t) {
				printf("%d %d %d %d\n", i, j, N[l].c, N[l].d);
				return;
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

