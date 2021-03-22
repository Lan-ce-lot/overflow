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
#include <unordered_map>
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
int t, n, k, s, e;
unordered_map<int, int> M;
vector<int> G[10000];
int vis[maxn], mintr = INF, minstep = INF;
set<int> S;
set<int> V;
set<int> T, T1;
vector<int> ans, tmp;
/*
最短路径
最少中转而非中转站 
*/
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (M[a[i-1] * 10000 + a[i]] != preLine) cnt++;
        preLine = M[a[i-1] * 10000 + a[i]];
    }
    return cnt;
}

void dfs(int u, int step) {
	if (u == e) {
		if (step < minstep || (step == minstep && transferCnt(tmp) < mintr)) {
			ans = tmp;
			minstep = step, mintr = transferCnt(tmp);
		}
		return;
	}
	
	
	for (int i = 0; i < G[u].size(); i++) {
		int t = G[u][i];
		if (!vis[t]) {
			tmp.push_back(t);
			vis[t] = 1;
			dfs(t, step + 1);
			tmp.pop_back();
			vis[t] = 0;
		}
	}

}
void solve() {
	n = read();
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		k = read(), tmp = read();T1.insert(tmp);
		for (int j = 1; j < k; j++) {
			t = read();
			G[tmp].push_back(t), G[t].push_back(tmp), M[tmp * 10000 + t] = i, M[t * 10000 + tmp] = i;
			if (V.count(t)) T.insert(t);
			T1.insert(t);
			tmp = t;
		}
		for (auto it : T1) V.insert(it);
	}
	t = read();
//	for (auto it : T) cout << it << ' ';
	for (int i = 0; i < t; i++) {
		s = read(), e = read();
		memset(vis, 0, sizeof vis);
		mintr = minstep = INF;
		ans.clear();
		tmp.clear();
		tmp.push_back(s);
		vis[s] = 1;
		dfs(s, 0);
		vis[s] = 0;
		tmp.pop_back();
		int b_f = s, last = 0, ind = 0;
		cout << minstep << endl;
		for (int j = 1; j < ans.size(); j++) {
			if (M[ans[j - 1] * 10000 + ans[j]] != last) {
				if (last) printf("Take Line#%d from %04d to %04d.\n", last, b_f, ans[j - 1]);
				last = M[ans[j - 1] * 10000 + ans[j]];
				b_f = ans[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", last, b_f, e);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

