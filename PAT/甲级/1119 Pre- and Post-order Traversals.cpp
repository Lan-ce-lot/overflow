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
int pre[maxn], post[maxn];
int in[maxn], ind = 0, flag = 1; 
void build(int pre_l, int pre_r, int po_l, int po_r) {
	if (pre_l == pre_r) {
		in[ind++] = pre[pre_l];
		return;
	}
	if (pre[pre_l] == post[po_r]) {
		int i = pre_l + 1;
		while (i <= pre_r && pre[i] != post[po_r - 1]) i++;
		if (i - pre_l > 1) 
			build(pre_l + 1, i - 1, po_l, po_l + (i - 1 - pre_l - 1));
		else flag = 0;
		in[ind++] = post[po_r];
		build(i, pre_r, po_r - 1 - (pre_r - i), po_r - 1);
	}
//	po_r - 1 - (pre_r - i)
}
void solve()
{
	n = read();
	for (int i = 0; i < n; i++) {
		pre[i] = read();
	}
	for (int i = 0; i < n; i++) {
		post[i] = read();
	}
	
	build(0, n - 1, 0, n - 1);
	if (flag) {
		puts("Yes");
	} else {
		puts("No");
	}
	cout << in[0];
	for (int i = 1; i < ind; i++) {
		cout << ' ' << in[i];
	}puts("");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

