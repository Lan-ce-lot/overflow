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
char M[6][6];
//int G[6][6];
int change[4][4];



void work() {
	
}

void solve()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				change[i][j] += 1 << i * 4 + k;
				change[i][j] += 1 << k * 4 + j;
			}change[i][j] -= 1 << i * 4 + j;
		}
	}
	for (int i = 0; i < 4; i++) {
		scanf("%s", M[i]);
	}
	int state = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (M[i][j] == '+') state += 1 << (i * 4 + j);
		}
	}
	vector<PII> res;
	for (int k = 0; k < 1 << 16; k++) {
		int now = state;
		vector<PII> tem;
		for (int i = 0; i < 16; i++) {
			if (k >> i & 1) {
				int xx = i / 4, yy = i % 4;
				now ^= change[xx][yy];
				tem.push_back({xx, yy});
			}
		}
		if (!now && (res.empty() || res.size() > tem.size())) {
			res = tem;
		}
	}
	cout << res.size() << endl;
	for (auto i : res) {
		cout << i.first + 1 << ' ' << i.second + 1 << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

