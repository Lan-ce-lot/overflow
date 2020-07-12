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
int t, n;
struct node
{
    int x;
    int y;
};
bool cmp(node a, node b)
{
    if (a.x < b.x)
        return 1;
    else if (a.x == b.x)
        return a.y < b.y;
    return 0;
}
node a[maxn];
void solve()//R U
{
    cin >> t;
    while (t--)
    {
        int flag = 0;
        string str = "";
        cin >> n;
        for (int i = 1; i < n + 1; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a + 1, a + n + 1, cmp);
//        for (int i  = 0; i < n; i++)
//        {
//            cout << a[i].x << a[i].y << endl;
//        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1].y > a[i].y)
            {
                puts("NO");
                flag = 1;
                break;
            }
            else
            {
                int co_x = a[i].x - a[i - 1].x;
                for (int j = 0; j < co_x; j++)
                    str += 'R';
                int co_y = a[i].y - a[i - 1].y;
                for (int j = 0; j < co_y; j++)
                    str += 'U';
            }
        }
        if (!flag)
        {
            puts("YES");
            cout << str << endl;
        }
    }
}

int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

