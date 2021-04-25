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
#include <chrono>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
unsigned seed = std::chrono::high_resolution_clock::now()
				 .time_since_epoch().count();
std::mt19937 mt(seed);
//sacnf("%lf") printf("%f")
int t, n, path[100];
void salesman_problem(int n, double &min, int t[], vector<vector<int> > c) {
	int p[n], i = 1;
	double cost;
	for (i = 0; i < n; i++) p[i] = i;
	min = INF;
	do {
		cost = 0;
		for (int i = 0; i < n - 1; i ++) 
			cost += c[p[i]][p[i + 1]];
		cost += c[p[n - 1]][p[0]];
		if (cost < min) { 
			for (i = 0; i < n - 1; i++)
				t[i] = p[i];
			min = cost;
//			cout << min << endl;
//			for (int i = 0; i < n - 1; i++) {
//				cout << t[i] << "->";
//			}
//			cout << t[0] << endl;
		}
	} while (next_permutation(p, p + n));
}
void solve() {
	while (n < 13) {
		n++;
		vector<vector<int> > c(n, vector<int> (n));
		double mincost = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				c[i][j] = 100 * mt() % 100;
			}
		}
		clock_t start = clock(), end;
		
		salesman_problem(n, mincost, path, c);
		end = clock();
		cout << n << ' ' << int(end - start) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
	}

	
//	cout << mincost << endl;
//	for (int i = 0; i < n - 1; i++) {
//		cout << path[i] << "->";
//	}
//	cout << path[0] << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

