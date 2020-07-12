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
int t, n, m, d[maxn], cnt = 0, ans;

struct node
{
    int a, b, w;
    bool operator< (const node &W)const
    {
        return w < W.w;
    }
};

vector<node> G;
bool vis[maxn];

int p[maxn];
int find(int x)
{
    return x == p[x] ? x : p[x] = find(p[x]);
}


void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.push_back({a, b, c});
    }

    sort(G.begin(), G.end());

    for (int i = 1; i <= m; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        if (cnt >= n - 1)
        {
            cout << ans << endl;
            return;
        }
        if (find(G[i].a) != find(G[i].b))
        {
            p[find(G[i].a)] = find(G[i].b);
            ans += G[i].w;
            cnt++;
//            debug(G[i].w);
        }
    }
    puts("impossible");
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

