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
int t, n, m, d[maxn], cnt[maxn];
vector<PII> G[maxn];
bool vis[maxn];
bool spfa()
{
    queue<int> Q;

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 1;
        Q.push(i);
    }

    while (Q.size())
    {
        int top = Q.front();
        Q.pop();

        vis[top] = 0;

        for (int i = 0; i < G[top].size(); i++)
        {
            int j = G[top][i].first;
            if (d[j] > d[top] + G[top][i].second)
            {
                d[j] = d[top] + G[top][i].second;
                cnt[j] = cnt[top] + 1;

                if (cnt[j] >= n) return 1;
                if (!vis[j])
                {
                    Q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    if (spfa())puts("Yes");
    else puts("No");

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

