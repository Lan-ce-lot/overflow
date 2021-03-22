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
int t, n, po[maxn], in[maxn];
unordered_map<int, int> M;
void build(int u, int i_l, int i_r, int p_l, int p_r) {
	if (p_l > p_r) {
		return;
	}
	int i = -1, v = po[p_r];
	while (v != in[++i]);
	M[u] = v;
	build(u << 1, i_l, i - 1, p_l, p_l + i - 1 - i_l);
	build(u << 1 | 1, i + 1, i_r, p_l + i - i_l, p_r - 1);
}

void solve()
{
	n = read();
	for (int i = 0; i < n; i++) {
		po[i] = read();
	}
	for (int i = 0; i < n; i++) {
		in[i] = read();
	}
	build(1, 0, n - 1, 0, n - 1);
	int num = 0;
	for (int i = 1; ; i++) {
		if (num == n)break;
		if (M[i] && num++) cout << ' ';
		if (M[i])
		cout << M[i];
	}
	puts("");
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

