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
int a[maxn];
int num[maxn];
//bool vis[maxn];
bool flag = 0;
vector<PII> ans;
int fi = 0;
void dfs(int sum, int step) {
	if (flag == 1) return;
	if (step >= n) {
		for (int i = 1; i < 1000005; i++) {
			if (num[i] == 1) {
				fi = i;
				break;
			}
		}
		flag = 1;
		
		puts("YES");
		cout << fi + a[2 * n - 1] << endl <<  fi << ' ' << a[2 * n - 1] << endl;
		for (auto it : ans) {
			cout << it.first << ' ' << it.second << endl;
		}
		return ;
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		if (a[i] > sum - a[i]) {
			break;
		}
		if (a[i] == sum - a[i]) {
			if (num[a[i]] >= 2) {
				num[a[i]]--;
				num[sum - a[i]]--;
				ans.push_back({a[i], sum - a[i]});
				dfs(sum - a[i], step + 1);
				ans.pop_back();
				num[a[i]]++;
				num[sum - a[i]]++;
			}
		}
		else if (num[a[i]] > 0 && num[sum - a[i]] > 0) {
			num[a[i]]--;
			num[sum - a[i]]--;
			ans.push_back({a[i], sum - a[i]});
			dfs(sum - a[i], step + 1);
			ans.pop_back();
			num[a[i]]++;
			num[sum - a[i]]++;
		}
	}
//	for (int i = 1; i <= sum; i++) {
//		if (i > sum - i) break;
//		if (i == sum - i) {
//			if (num[i] >= 2) {
//				num[i]--;
//				num[sum - i]--;
//				ans.push_back({i, sum - i});
//				dfs(sum - i, step + 1);
//				ans.pop_back();
//				num[i]++;
//				num[sum - i]++;
//			}
//		} else if (num[i] > 0 && num[sum - i] > 0) {
//			num[i]--;
//			num[sum - i]--;
//			ans.push_back({i, sum - i});
//			dfs(sum - i, step + 1);
//			ans.pop_back();
//			num[i]++;
//			num[sum - i]++;
//		}
//	}
}


void solve()
{
	t = read();
	while (t--) {
		ans.clear();
		memset(num, 0, sizeof num);
		flag = 0;
		n = read();
		for (int i = 0; i < 2 * n; i++) {
			a[i] = read();
			num[a[i]] ++;
		}
		sort(a, a + 2 * n);
//		n = 2 * n;
		num[a[2 * n - 1]] --;
		dfs(a[2 * n - 1], 1);
		if (flag) {

			
		} else {
			puts("NO");
		}
//		cout << flag << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

