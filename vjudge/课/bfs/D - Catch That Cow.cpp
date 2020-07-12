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
int t, s, e;
bool vis[maxn];

bool test(int x) {return x >= 0 && x <= 140005 && !vis[x]; }

void bfs(int x, int s) {
    queue<PII> Q;
    Q.push({x, 0});
    vis[x] = 1;
    while (!Q.empty()) {
         PII top = Q.front();
         Q.pop();
         if (top.first == e) {cout << top.second << endl; return;}
         // +1
         int xx = top.first + 1;

         if (test(xx)) {
            vis[xx] = 1;
            Q.push({xx, top.second + 1});
         }
         // -1
         xx = top.first - 1;
         if (test(xx)) {
            vis[xx] = 1;
            Q.push({xx, top.second + 1});
         }
         // *2
         xx = top.first * 2;
         if (test(xx)) {
            vis[xx] = 1;
            Q.push({xx, top.second + 1});
         }
    }
}



void solve()
{
    cin >> s >> e;
    bfs(s, 0);
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

