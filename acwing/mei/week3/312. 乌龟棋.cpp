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
int t, n, m;
int maze[maxn];
int num[maxn];
int f[50][50][50][50];
void solve()
{
	n = read(), m = read();
	for (int i = 0; i < n; i++) {
		maze[i] = read();
	}
	for (int i = 1; i <= m; i++) {
		int tmp =read();
		num[tmp]++;
	}
	for (int i = 0; i <= num[1]; i++) {
		for (int j = 0; j <= num[2]; j++) {
			for (int k = 0; k <= num[3]; k++) {
				for (int l = 0; l <= num[4]; l++) {
					int t = maze[i * 1 + j * 2 + k * 3 + l * 4];
					int &v = f[i][j][k][l];
					v = t;// f[0][0]
					if (i) {
						v = max(v, f[i - 1][j][k][l] + t);
					}
					if (j) {
						v = max(v, f[i][j - 1][k][l] + t);
					}
					if (k) {
						v = max(v, f[i][j][k - 1][l] + t);
					}
					if (l) {
						v = max(v, f[i][j][k][l - 1] + t);
					}
				}
			}
		}
	}
	cout << f[num[1]][num[2]][num[3]][num[4]] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

