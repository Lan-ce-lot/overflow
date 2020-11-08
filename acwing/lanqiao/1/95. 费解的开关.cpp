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
// 第一行锁定 
char G[6][6];
int dir[5][2] = {0, 0, 1, 0, -1, 0, 0, -1, 0, 1};

void turn(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5) {
			G[xx][yy] ^= 1;
		}
	}
}


int work() {
	int res = INF;
	for (int k = 0; k < 1 << 5; k++) {
		int tem = 0;
		char backup[6][6];
		memcpy(backup, G, sizeof G);
		
		
		// first 0
		for (int i = 0; i < 5; i++) {
			if (k >> i & 1) {
				tem++;
				turn(0, i);
			}
		}
		
		
		// 1-3
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {
				if (G[i][j] == '0') {
					tem++;
					turn(i + 1, j);
				}
			}
 		}
		
		// check 4
		int flag = 0;
		for (int j = 0; j < 5; j++) {
			if (G[4][j] != '1') {
				flag = 1;
				break;
			}
		}
		if (!flag) res = min(res, tem);
		memcpy(G, backup, sizeof backup);
	}
	if (res > 6) res = -1;
	return res;
}

void solve()
{
	t = read();
	n = 5;
	while (t--) {
		for (int i = 0; i < n; i++) {
			cin >> G[i];
		}
//		for (int i = 0; i < n; i++) {
//			cout << G[i] << endl;
//		}
		cout << work() << endl;
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

