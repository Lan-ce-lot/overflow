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
int z[maxn], x[maxn];
int tree[maxn];

int return_tree(int z1, int z2, int x1, int x2) {
	if (z2 - z1 == 0) {
		return x1;
	}
	if (z2 - z1 < 0) {
		return -1;
	}
	int root = x1;
	int pos = 0;
	for (int i = z1; i <= z2; i ++) {
		
		if (z[i] == x[root]) {
			pos = i;
		}
	}
	
	tree[root << 1] = return_tree(z1, pos - 1, x1 + 1, x1 + pos - z1);
	tree[root << 1 | 1] = return_tree(pos + 1, z2, x1 + pos - z1 + 1, x2);
	return root;
	
}
vector<int> V;
void print(int n) {
	int tem = 0;
	queue<int> Q;
	while (Q.size()) {
		tem = Q.front();
		
		Q.pop();
		V.push_back(b[tem]);
		if (tree[tem << 1 | 1] != -1) {
			Q.push(tree[tem << 1 | 1]);
		} 
		if (tree[tem << 1] != -1) {
			Q.push(tree[tem << 1 | 1]);
		}
		
	}
}

void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		z[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		x[i] = read();
	}
	return_tree();
	
    cout<<*V.begin();
    for (vector<int>::iterator it=V.begin()+1;it!=V.end();it++)
        cout<<' '<<*it;
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

