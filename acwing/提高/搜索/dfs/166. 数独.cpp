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
int a[maxn];
bool vis[maxn];
int ans = 0;

int lowbit(int x) {
	return x & -x;
}


int ma[1 << 10];
int one[1 << 10];// 1 count
int row[10], col[10], cell[3][3];
string str, str2, str3;

void init() {
	for (int i = 0; i < 9; i++) row[i] = col[i] = (1 << 9) - 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cell[i][j] = (1 << 9) - 1;
}
void draw(int x, int y, int t, bool is_set)
{
    if (is_set) str[x * 9+ y] = '1' + t;
    else str[x * 9 + y] = '.';

    int v = 1 << t;
    if (!is_set) v = -v;

    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}
int get(int x, int y) {
	return row[x] & col[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
	if (cnt == 0) return 1;
	
	int maxx = 10;
	int x, y;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (str[i * 9 + j] == '.') {
				int t = one[get(i, j)];
				if (t < maxx) {
					maxx = t;
					x = i, y = j;
				}
			}
		}
	}
	for (int i = get(x, y); i; i -= lowbit(i)) {
		int t = ma[lowbit(i)];
		draw(x, y, t, true);
//		row[x] -= 1 << t;
//		col[y] -= 1 << t;
//		cell[x / 3][y / 3] -= 1 << t;
//		str[x * 9 + y] = '1' + t;
		if (dfs(cnt - 1)) return 1;
		draw(x, y, t, false);
//		row[x] += 1 << t;
//		col[y] += 1 << t;
//		cell[x / 3][y / 3] += 1 << t;
//		str[x * 9 + y] = '.';
	}
	return 0;
	
}

void solve()
{
	for (int i = 0; i < 9; i++) ma[1 << i] = i;
//	for (int i = 0; i < 1 << 9; i++) {
//		int s = 0;
//		for (int j = i; j; j -= lowbit(j)) s++;
//		one[i] = s;
//	}
    for (int i = 0; i < 1 << 9; i ++ )
        for (int j = 0; j < 9; j ++ )
            one[i] += i >> j & 1;	
	
	while (cin >> str) {
		if (str[0] == 'e') return;
		init();
//		n = 9;
//		cout << str << endl;
//		cin >> str1 >> str2 >> str3;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << str1[i * 9 + j] << ' ';
//			}
//			puts("");
//		}	
		int cnt = 0;	
		for (int i = 0, k = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++, k++) {
				if (str[k] != '.') {
					int t = str[k] - '1';
					draw(i, j, t, true);
//					draw(i, j, t, true);
//					row[i] -= 1 << t;
//					col[j] -= 1 << t;	
//					cell[i / 3][j / 3] -= 1 << t;				
				}
				else cnt++;
			}
		}
		dfs(cnt);
		cout << str << endl;
	}
	

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

