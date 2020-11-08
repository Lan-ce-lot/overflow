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
int t, n, m, pr[maxn], cnt = 0;
bool vis[maxn];

void get_p(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			pr[cnt++] = i;
		}
		for (int j = 0; pr[j] <= n / i; j++) {
			vis[pr[j] * i] = 1;
			if (i % pr[j] == 0) break;
		}
	}
}

void solve()
{
	get_p(maxn);
	n = read(), m = read();
	int co = 0;
	for (int i = n - 1; i <= m - 1; i++) {
		cout << pr[i];
		co++;
		if (i == m - 1) {
			puts("");return;
		}
		if (co % 10 == 0) {
			puts("");
		} else {
			printf(" ");
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

