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
int p[maxn];
struct node
{
    int u, v, w;
};

node maze[maxn];
int ans = 0;
bool cmp(node a, node b)
{
    return a.w < b.w;
}

void init()
{
    for (int i = 0; i < maxn; i++)
        p[i] = i;
}

int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = Find(p[x]);
}

void Union(int x, int y, int i)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
    {
        ans += maze[i].w;
        p[x] = y;
    }
}

int lcm(int x, int y)  {
	return x * y / __gcd(x, y);
}

int t, n, k;
void solve()
{
	t = read();
	while (t--) {
		ans = 0;
		init();
		n = read();
//		k = read();
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (i != j) {
					maze[tot++]= {i, j, lcm(i + 1, j + 1)};
				}
			}
		}sort(maze, maze + tot, cmp);
        for (int i = 0; i < tot; i++)
        {
            Union(maze[i].u, maze[i].v, i);
        }
		cout << ans << endl;
	}
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

