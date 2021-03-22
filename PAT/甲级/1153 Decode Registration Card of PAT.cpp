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
const int maxn = 10005;
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
struct node {
	string id;
	int sore;
	bool operator < (node &W) {
		if (sore != W.sore) return sore > W.sore;
		return id < W.id;
	}
}N[maxn], M1[maxn];


void solve()
{
	n = read(), m = read();
	for (int i = 0; i < n; i++) {
		cin >> N[i].id >> N[i].sore;
	}
	for (int con = 1; con <= m; con++) {
		int ty;string ss;
		cin >> ty >> ss;
		printf("Case %d: %d %s\n", con, ty, ss.c_str());
		if (ty == 1) {
			vector<node> ans1;
			for (int i = 0; i < n; i++)
				if (N[i].id[0] == ss[0]) ans1.push_back(N[i]);
			sort(ans1.begin(), ans1.end());
			if (ans1.size()) 
				for (int i = 0; i < ans1.size(); i++)
					printf("%s %d\n", ans1[i].id.c_str(), ans1[i].sore);
			else puts("NA");
		} else if (ty == 2) {
			int num = 0, sor = 0;
			for (int i = 0; i < n; i++)
				if (N[i].id.substr(1, 3) == ss) sor += N[i].sore, num++;
			if (num) printf("%d %d\n", num, sor);
			else puts("NA");
		} else if (ty == 3) {
			unordered_map<string, int> M; 
			vector<node> A3;
			for (int i = 0; i < n; i++) 
				if (N[i].id.substr(4, 6) == ss) M[N[i].id.substr(1, 3)]++;
			for (auto i:M)
				A3.push_back({i.first, i.second});
			sort(A3.begin(), A3.end());
			if (M.size()) 
				for (int i = 0; i < A3.size(); i++)
					printf("%s %d\n", A3[i].id.c_str(), A3[i].sore);
			else puts("NA");
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

