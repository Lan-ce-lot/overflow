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
int  n;
struct node
{
    int x,y;
} t[maxn];
/*
4
1 0
1 2
2 2
3 4

*/
void solve()
{
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        t[i].x = read();
        t[i].y = read();

    }
    for (int i = 0; i < n; i++)
    {
        double a, b, c;
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                a = (t[i].x - t[j].x) * (t[i].x - t[j].x) + (t[i].y - t[j].y) * (t[i].y - t[j].y);
                b = (t[k].x - t[j].x) * (t[k].x - t[j].x) + (t[k].y - t[j].y) * (t[k].y - t[j].y);
                c = (t[i].x - t[k].x) * (t[i].x - t[k].x) + (t[i].y - t[k].y) * (t[i].y - t[k].y);
                if (a > b)
                {
                    if (a > c)
                    {
                        if (sqrt(a) >= sqrt(b) + sqrt(c))
                        {
                            continue;
                        }
                        else if (a > b + c)
                        {
                            ans++;
                        }
                    }
                    else
                    {
                        if (sqrt(c) >= sqrt(b) + sqrt(a))
                        {
                            continue;
                        }
                        else if (c > b + a)
                        {
                            ans++;
                        }
                    }
                }
                else if (b > a)
                {
                    if (b > c)
                    {
                        if (sqrt(b) >= sqrt(a) + sqrt(c))
                        {
                            continue;
                        }
                        else if (b > a + c)
                        {
                            ans++;
                        }
                    }
                    else
                    {
                        if (sqrt(c) >= sqrt(b) + sqrt(a))
                        {
                            continue;
                        }
                        else if (c > b + a)
                        {
                            ans++;
                        }
                    }
                }

            }
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

