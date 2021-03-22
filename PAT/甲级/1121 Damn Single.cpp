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
map<int,int> M, r_M;
set<int> S, ans;
void solve()
{
	n = read();
	for (int i = 0; i <= 99999; i++) M[i] = -1;
	for (int i = 0; i < n; i++) {
		int tmp = read(), tm = read();
		M[tmp] = tm, M[tm] = tmp;
	}
	
	n = read();
	for (int i = 0; i < n; i++) {
		S.insert(read());
	}
	for (auto it : S) {
		if (S.count(M[it]) == 0) {
			ans.insert(it);
		}
	}
	int con = 0;
	cout << ans.size() << endl;
	if (ans.size() == 0) return;
	for (auto it : ans) {
		con++;
		if (con != 1) {
			cout << ' ';
		}
		printf("%05d", it);
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

