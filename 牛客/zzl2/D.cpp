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
int t, n, q;
vector<int> G[maxn];
bool vis[maxn];
ll con1[maxn];
void bfs(int t) {
    memset(vis, 0, sizeof vis);
    queue<int> Q;
    Q.push(t);
    vis[t] = 1;
    int con = 0;
    con1[t]++;
    int ee = G[t][G[t].size() - 1];
    while (Q.size()) {
        con++;
//        if (con > 8) return;
        int top = Q.front();
//        debug(top);
        Q.pop();
        for (int i = 0; i < G[top].size(); i++) {
            if (!vis[G[top][i]]) {
                vis[G[top][i]] = 1;
                con1[G[top][i]]++;
                Q.push(G[top][i]);
            }
        }
        if (ee == top) return ;
    }
}

void solve()
{
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < q; i++) {
        cin >> t;
        bfs(t);
        cout << con1[t] << endl;
    }
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

