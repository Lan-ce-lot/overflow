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
int a[maxn], cnt[maxn];
struct node {
	int num, cnt;
	bool operator < (node &W) const {
		if (cnt == W.cnt)
			return num < W.num;
		return cnt > W.cnt;
	}
};
vector<node> S;
set<int> SS;
void solve()
{
	n = read(), m = read();
	for (int i = 0; i < n; i++)
		a[i] = read();
	int all = 1;
	S.push_back({a[0], 1});
	cnt[a[0]]++;
	SS.insert(a[0]);
	for (int i = 1; i < n; i++) {
		cout << a[i] << ":";
		for (int j = 0; j < S.size(); j++) 
			printf(" %d%s", S[j].num, j == S.size() - 1 ? "\n" : "");
			
			if (SS.count(a[i])) {
			++cnt[a[i]];
		} else {
			S.push_back({a[i], ++cnt[a[i]]});
			SS.insert(a[i]);all++;
		}
		for (int j = 0; j < S.size(); j++) {
			S[j].cnt = cnt[S[j].num];
		}
		
		sort(S.begin(), S.end());
		if (all > m) {
			SS.erase(S[S.size() - 1].num);
			S.pop_back();
			all--;
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

