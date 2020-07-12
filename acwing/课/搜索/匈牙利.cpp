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
int t, n1, n2, m;//n1左,n2右
vector<int> G[maxn];
bool vis[maxn];//第二个集合的点是否被遍历过
int match[maxn];//下标右匹配值左

bool find(int x)
{
    for (int i =0; i < G[x].size(); i++)
    {
        int j = G[x][i];
        if (!vis[j])
        {
            vis[j] = 1;
            if (match[j] == 0 || find(match[j]))//未匹配或可以腾位
            {
                match[j] = x;
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    int ans = 0;
    for (int i = 1; i <= n1; i++)//枚举集合一的点
    {
        memset(vis, 0, sizeof vis);
        if (find(i))
            ans++;
    }
    cout << ans << endl;

}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

