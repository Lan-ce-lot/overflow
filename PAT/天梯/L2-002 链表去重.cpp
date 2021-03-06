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
#include <unordered_map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define x first
#define y second
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
struct node {
	int st;
	int ab;
};
vector<node> DEL, ans;
bool vis[maxn];
unordered_map<int, PII> m{{-1, {INF, -1}}}; 
void solve()
{
	int start;
	cin >> start >> n;
	for (int i = 0; i < n; i++) {
		int st = read(), v = read(), en = read();
		m[st] = {v, en};
	}
	int p = 0, q = start, r = m[start].y;
	while (q != -1) {
		int v = m[q].x;
		int ne = m[q].y;
		if (vis[abs(v)]) {
			DEL.push_back({q, m[q].x});	
			m[p].y = m[q].y;
		} else {
			vis[abs(v)] = 1;
			ans.push_back({q, m[q].x});	
		}
		p = q;
		q = m[q].y;
		if (q == -1) {
			break;
		}
		
	}
	p = 0, q = start;
	while (q != -1) {
		if (m[q].y == -1) {
			
			printf("%05d %d -1\n",q,m[q].x,m[q].y);
		}
		
		else {
			
			printf("%05d %d %05d\n",q,m[q].x,m[q].y);
		}
		q = m[q].y;
	}
//	for (int i = 0; i < ans.size(); i++) {
//		if (i == ans.size() - 1) printf("%05d %d -1\n", ans[i].st, ans[i].ab);
//		else printf("%05d %d %05d\n", ans[i].st, ans[i].ab, ans[i + 1].st);
//	}
	
	for (int i = 0; i < DEL.size(); i++) {
		if (i == DEL.size() - 1) printf("%05d %d -1\n", DEL[i].st, DEL[i].ab);
		else printf("%05d %d %05d\n", DEL[i].st, DEL[i].ab, DEL[i + 1].st);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

