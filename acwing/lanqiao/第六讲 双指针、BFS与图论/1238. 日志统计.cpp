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
int t, n, d, k;
int con[maxn];
struct node {
	int x, y;
}Node[maxn];
bool cmp (node a, node b) {
	if (a.y != b.y) {
		return a.y < b.y;
	} else {
		return a.x < b.x;
	}
}
set<int> S;
void solve()
{
	n = read(), d = read(), k = read();
	for (int i = 0; i < n; i++) {
		Node[i].x = read(), Node[i].y = read();
		S.insert(Node[i].y);
	}
	sort(Node, Node + n, cmp);
	int now = Node[0].y;
	int last_i = 0;
	int now_t = Node[0].x;
	con[now] = 1;
//	for (int i = 0; i <= n; i++) {
//		
//	}
	for (int i = 1; i < n; i++) {
		if (Node[i].y == now) {
			while (Node[last_i].x + d <= Node[i].x && last_i < i) {
				last_i++;
			}
			con[now] = max(con[now], i - last_i + 1); 
		} else {
			now = Node[i].y;
			last_i = i;
			now_t = Node[i].x;
			con[now] = 1;
		}
//		cout << Node[i].x << ' ' << Node[i].y << endl;
	}
	
	for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
		if (con[*it] >= k) {
			cout << *it << endl;
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

