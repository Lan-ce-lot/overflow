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
int t, n;string from, to;
void turn(int i) {
	if (from[i] == '*') from[i] = 'o';
	else from[i] = '*';
}
void solve()
{
	
	cin >> from >> to;
	int st = 0, en = 0;
	int ind_l = 0, ind_r = from.size() - 1;
	while (from[ind_l] == to[ind_l]) {
		ind_l ++;
	}
	while (from[ind_r] == to[ind_r]) {
		ind_r --;
	}
//	debug(ind_l);
//	debug(ind_r);
int res = 0;
	from = from.substr(ind_l, ind_r - ind_l + 1);
	to = to.substr(ind_l, ind_r - ind_l + 1);
//	cout << from << endl << to << endl;
	for (int i = 0; i < from.size() - 1; i++) {
		if (from[i] != to[i]) {
			turn(i), turn(i + 1);
			res++;
//			st += 1 << i;
		}
	}
	cout << res << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

