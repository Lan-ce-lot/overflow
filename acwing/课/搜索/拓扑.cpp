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
int t, n, m;
vector<int> G[maxn];
int du[maxn];//入度
int ans[maxn];//排序结果
bool bfs()//拓扑序
{
    int cnt = 0;
    queue<int> Q;
    for (int i = 1; i <= n; i++)
    {
        if(!du[i]) Q.push(i), cnt++;
    }
    int j = 0;
    while (Q.size())
    {
        int top = Q.front();
        Q.pop();
        ans[j++] = top;
        for (int i = 0; i < G[top].size(); i++)
        {
            if (--du[G[top][i]] == 0)
                Q.push(G[top][i]), cnt++;
        }
    }
//debug(cnt);
    return cnt == n;
}


void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        du[b]++;
    }
//    bfs();
    if (bfs())
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
    }
    else
    {
        puts("-1");
    }

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

