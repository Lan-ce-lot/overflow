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
const int maxn = 300005;
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
string str;
int a[maxn], q[maxn];
struct node{
	int l, r;
	int ma, cnt;
}tr[maxn * 4];

void pushup(int u) {
	tr[u].ma = tr[u << 1].ma + tr[u << 1 | 1].ma;
	tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
}

void build(int u, int l, int r) {
	tr[u] = {l, r};
	if (l == r) {
		if (a[l] == 0) {
			tr[u].cnt++;
		}
		if (a[l] != INF) 
			tr[u].ma = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

int query(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].ma;
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid) return query(u * 2, l, r);
	else if (l > mid) return query(u * 2 + 1, l, r);
	return query(u * 2, l, mid) + query(u * 2 + 1, mid + 1, r);
}
int cnt_q(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].cnt;
	int mid = tr[u].l + tr[u].r >> 1;
	if (r <= mid) return cnt_q(u * 2, l, r);
	else if (l > mid) return cnt_q(u * 2 + 1, l, r);
	return cnt_q(u * 2, l, mid) + cnt_q(u * 2 + 1, mid + 1, r);	
}
int tt[maxn];
void solve()
{
	t = read();
	while (t--) {
////		l = 1, r = 0;
//		memset(a, 0, sizeof a);
//		memset(q, 0, sizeof q);
		memset(a, INF, sizeof a);
		for (int i = 0; i < maxn * 4; i++) {
			tr[i].ma = 0;
			tr[i].cnt = 0;
		}
//		memset(tr[].ma, 0, sizeof tr);
//		memset(tr[].cnt, 0, sizeof tr);
		n = read();
		m = read();
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (i == '1') a[i + 1] = 1;
			else if (i == '0') a[i + 1] = -1;
			else a[i + 1] = 0;
		}
		int tem = 0;
		int flag = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j += m) {
				
				if (j == 1) {
					tem = a[j];
				} else {
					if (a[j] == tem) {
						tem = a[j];
						tt[i] = tem;
					} else if (a[j] == 0){
						tem = tem;
						
					} else if (tem == 0) {
						tem = a[j];
						tt[i] = tem;
					}
				}
			}
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

