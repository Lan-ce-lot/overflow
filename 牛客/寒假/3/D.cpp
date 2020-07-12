/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;

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
ll t, n, m, p;
struct node
{
    int x, y, v;
} nn[10005];

int aa[maxn][maxn];
void solve()
{
    cin >> t;
    while (t--)
    {
        int flag = 0;
        cin >> n >> m >> p;

        memset(aa, 0, sizeof(aa));
        for (int i = 0; i < p; i++)
        {
            cin >> nn[i].x >> nn[i].y >> nn[i].v;
        }
        for (int i = 0; i < p; i++)
        {
            if (nn[i].x >= 0 && nn[i].y >=0 && nn[i].x < n && nn[i].y < m)
            {
                aa[nn[i].x][nn[i].y] = nn[i].v;
            }
            else
            {
                if (nn[i].x * m + nn[i].y >= 0 && nn[i].x * m + nn[i].y < n * m)
                {
//                    (nn[i].x * m + nn[i].y) / m;
//                    (nn[i].x * m + nn[i].y) % m;
                    flag = 1;
                    aa[(nn[i].x * m + nn[i].y) / m][(nn[i].x * m + nn[i].y) % m] = nn[i].v;
                }
                else
                {
                    flag = 2;
                    break;
                }
            }
        }
        if (flag == 2)
        {
            puts("Runtime error");
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << aa[i][j] << (j == m - 1?'\n' : ' ');
                }
            }
            if (flag == 0)
            {
                puts("Accepted");
            }
            else
            {
                puts("Undefined Behaviour");
            }
        }

    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

