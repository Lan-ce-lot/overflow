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
int t, n, k, a;
// 家庭成员的最小编号 家
// 庭人口数 人均房产套数 人均房产面积

// 编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积
struct node {
	int id, f_id, m_id, house, area;
	vector<int> Kis; 
}N[maxn];
// 家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
int p[maxn], size[maxn], ho[maxn], ave_area[maxn];
struct no {
	// 家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积
	// 面积降序输出，若有并列，则按成员编号的升序输出
	int id, num;
	double ave_h, ave_ar;
	bool operator< (no &W) {
		if (ave_ar == W.ave_ar) return id < W.id; 
		return ave_ar > W.ave_ar;
	}
};
vector<no> ANS;
map<int, int> M, RM;
int tot = 1;
int find(int x) {
	if (x != p[x])
		return p[x] = find(p[x]);
	return p[x];
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (M[x] < M[y]) {
			p[y] = x;
			size[x] += size[y];
			ho[x] += ho[y];
			ave_area[x] += ave_area[y]; 
			size[y] = ho[y] = ave_area[y] = 0;
		} else {
			swap(x, y);
			p[y] = x;
			size[x] += size[y];
			ho[x] += ho[y];
			ave_area[x] += ave_area[y]; 
			size[y] = ho[y] = ave_area[y] = 0;
		}
	}
}


void solve()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> N[i].id >> N[i].f_id >> N[i].m_id >> k;
		if (RM.count(N[i].id) == 0) RM[N[i].id] = tot, M[tot++] = N[i].id;
		if (~N[i].f_id && RM.count(N[i].f_id) == 0) 
			RM[N[i].f_id] = tot, M[tot++] = N[i].f_id;
		if (~N[i].m_id && RM.count(N[i].m_id) == 0) 
			RM[N[i].m_id] = tot, M[tot++] = N[i].m_id;
		for (int j = 0; j < k; j++) {
			cin >> a;
			if (RM.count(a) == 0)
				RM[a] = tot, M[tot++] = a;
			N[i].Kis.push_back(a); 
		}
		cin >> N[i].house >> N[i].area;
	}
	for (int i = 1; i < tot; i++) {
		p[i] = i;
		size[i] = 1, ho[i] = 0, ave_area[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		ho[RM[N[i].id]] = N[i].house;
		ave_area[RM[N[i].id]] = N[i].area;
	}
//	for (auto it : M) cout << it.first << ' ' << it.second << endl;
	for (int i = 1; i <= n; i++) {
		if (~N[i].f_id)
			Union(RM[N[i].id], RM[N[i].f_id]);
		if (~N[i].m_id)
			Union(RM[N[i].id], RM[N[i].m_id]);
		for (auto it : N[i].Kis) {
			Union(RM[N[i].id], RM[it]);
		}
	}
	int ans = 0;
	for (int i = 1; i < tot; i++) {
		if (find(i) == i) {
			ans++;
			ANS.push_back({M[i], size[i], ho[i] * 1. / size[i], 
			ave_area[i] * 1. / size[i]});
		}
	}
	sort(ANS.begin(), ANS.end());
	cout << ans << endl;
	for (auto it : ANS) {
		printf("%04d %d %.3lf %.3lf\n", it.id, it.num, it.ave_h, it.ave_ar);
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

