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
int x, y, a, b;
string str[105];
string ans, ansr, center;
bool vis[105];
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    int flag = 0, len = 0;;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vis[i] == 1 || vis[j] == 1)
                continue;
            flag = 0;
            for (int k = 0; k < m; k++)
            {
                if (str[i][k] != str[j][m - k - 1])
                {
                    flag = 1;
                }
            }
            if (flag != 1)
            {
                vis[i] = 1;
                vis[j] = 1;
                ans += str[i];
                ansr += str[i];
                len += 2 * m;
            }
        }
    }
    flag = 0;
    center = "";
    reverse(ansr.begin(), ansr.end());
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        if (!vis[i])
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (str[i][j] != str[i][m - j - 1])
                {
//                    cout << i << ' ' << j << ' ';
//                    debug(str[i][j]);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                center = str[i];
                len += m;
                break;
            }
        }
    }
//    debug(center);
    cout << len << endl << ans + center + ansr << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

