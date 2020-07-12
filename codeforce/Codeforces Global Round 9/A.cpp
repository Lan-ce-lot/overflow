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
int num[maxn];
bool vis[1005][1005];
int dir[4][2] = {0, -1, -1, 0, 1, 0, 0, 1};

int G[1005][1005];
int con[1005][1005];
//void dfs(int x, int y) {
//	
//}

bool test(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i][0], yy = x + dir[4][1];
		if (test(xx, yy)) {
			
		}
	}
	
	
	vis[x][y] = 1;
	
	
	
}

void solve()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> G[i][j];
			}
		}
		int flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0 || i == n - 1 && j == 0 || i == 0 && j == m - 1 || i == n - 1 && j == m - 1) {
					if (G[i][j] > 2) {
						puts("NO");
						flag = 1;
						break;
					} 
				} else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					if (G[i][j] > 3) {
						puts("NO");
						flag = 1;
						break;
					}
				} else {
					if (G[i][j] > 4) {
						puts("NO");
						flag = 1;
						break;
					}
				}
			}
			if (flag) break;
		}		
		if (flag) continue;
		else puts("YES");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0 || i == n - 1 && j == 0 || i == 0 && j == m - 1 || i == n - 1 && j == m - 1) {
					G[i][j] = 2;
				} else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					G[i][j] = 3;
					
				} else {
					G[i][j] = 4;
				}
			}
		}
		
		
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				if (G[i][j]) {
//					for (int k = 0; k < 4; k++) {
//						if (i + dir[k][0] >= 0 && i + dir[k][0] < n && j + dir[k][1] >= 0 && j + dir[k][1] < m) {
//							if (flag >= G[i][j]) break;
//							if (G[i + dir[k][0]][j + dir[k][1]]) {
//								flag++;
//								
//							} else {
//								G[i + dir[k][0]][j + dir[k][1]] = 1;
//							}
//						}
//					}
//				}
//			}
//		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (j != 0) cout << ' ';
				cout << G[i][j];
			}
			puts("");
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

