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
int  a[maxn];
set<int> S, res;
map<int, int> id;
map<int, int> r_id;
bool check(int n) {
	if (n == 1) {
		return 0;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
void solve()
{
	n = read();
	for (int i = 0; i < n; i++) {
 		id[i] = read();
 		r_id[id[i]] = i;
 		res.insert(id[i]);
	}
	t = read();
	for (int i = 0; i < t; i++) {
		a[i] = read();
		if (res.count(a[i]) == 0) {
			printf("%04d: Are you kidding?\n", a[i]);
			continue;
		}
		
		if (S.count(a[i])) {
			printf("%04d: Checked\n", a[i]);
		} else if (r_id[a[i]] == 0) {
			printf("%04d: Mystery Award\n", a[i]);
		} else if(check(r_id[a[i]] + 1)) {
			printf("%04d: Minion\n", a[i]);
		} else {
			printf("%04d: Chocolate\n", a[i]);
		}S.insert(a[i]);
	}
 }

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

