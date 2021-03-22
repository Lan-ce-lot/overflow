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
int p[maxn], id[maxn], fa[maxn], ma[maxn], se[maxn], area[maxn], r_id[maxn];
int man[maxn];
int find(int x) {
	if (p[x] != x) {
		return p[x] = find(p[x]);
	} else {
		return x;
	}
}

void Union(int x, int y) {
	x = find(x), y = find(y); 
	if (x != y) {
		if (x < y) {
			p[y] = x;
			se[x] += se[y];
			area[x] += area[y];
			man[x] += man[y];
		}
		else {
			p[x] = y;
			se[y] += se[x];
			area[y] += area[x];
			man[y] += man[x];
		}
	}
}
struct node {
	int id, man;
	double c, area;
	bool operator < (node W) {
		if (area == W.area) {
			return id < W.id;
		}
		return area > W.area;
	}
};
vector<int> child[10000];
vector<node> res;
int ind = 1;
vector<int> S;
set<int> ss;
void solve()
{
	n = read();

	for (int i = 1; i <= n; i++) {
		
		id[i] = read();
		S.push_back(id[i]);
		int iid = id[i];
		fa[iid] = read(), ma[iid] = read();
		ss.insert(iid);
		if (fa[iid] != -1)
		ss.insert(fa[iid]);
		if (ma[iid] != -1)
		ss.insert(ma[iid]);
		int k = read();
		for (int j = 0; j < k; j++) {
			int rr = read();ss.insert(rr);
			child[iid].push_back(rr);
		}
		se[iid] = read(), area[iid] = read();
	}
	for (int i = 0; i <= 9999; i++) {
		p[i] = i;
		man[i] = 1;
	}
	for (int j = 0; j < S.size(); j++) {
		int i = S[j];
		if (fa[i] != -1) Union(i, fa[i]);
		if (ma[i] != -1) Union(i, ma[i]);
		for (int j = 0; j < child[i].size();j++) {
			Union(i, child[i][j]);
		}
	}
	int cnt = 0;
	for (auto it : ss) {
		int i = it;
		if (i != -1 && p[i] == i) {
			cnt++;
			res.push_back({i, man[i], se[i] / 1.0 / man[i], area[i] / 1.0 / man[i]});
		}
	}
	sort(res.begin(), res.end());
	cout << cnt << endl; 
	for (int i = 0; i < res.size(); i++) {
		printf("%04d %d %.3lf %.3lf\n", res[i].id, res[i].man, res[i].c , res[i].area);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

