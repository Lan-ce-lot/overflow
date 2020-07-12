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

const int N = 5e4 + 10;

struct Node {
	int a, b, i;
} p[N];
int n, f[N], c[N];

bool cmp (Node o1, Node o2) {
	return o1.a < o2.a;
}

int find (int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (p[mid].a < x) l = mid + 1;
		else r = mid;
	}
	return p[l].a >= x ? l : l+1;
}

int search (int x) {
	int r = x;
	while (f[r] != r) r = f[r];
	int i = x, j;
	while (f[i] != r) {
		j = f[i];
		f[i] = r;
		i = j;
	}
	return r;
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].a, &p[i].b);
		p[i].i = i;
		f[i] = i;
	}
	f[n+1] = n+1;
	sort(p + 1, p + n + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] != i) continue;
		cnt++;
		int j = i;
		while (true) {
			f[j] = j + 1;
			c[p[j].i] = cnt;
			j = find(p[j].b+1);
			if (j > n) break;
			j = search(j);
			if (j > n) break;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", c[i]);
	}
	return 0;
}


