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
const int maxn = 1e5 + 5;
int a[maxn];
vector<int> ans;
set<int> S;
int t, n;
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
void solve()
{
    ans.clear();
    S.clear();
    n = read();
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
        S.insert(i + 1);
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] > temp)
        {

            temp = a[i];
            if (S.count(a[i]))
            {
                S.erase(a[i]);
                ans.push_back(a[i]);
            }
            else
            {
                cout << "-1" << endl;
                return;
            }
        }
        else
        {
            if (*S.begin() > temp)
            {

                cout << "-1" << endl;
                return;
            }
            else
            {
                ans.push_back(*S.begin());
                S.erase(*S.begin());
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << ' ';
    }
    puts("");
}

int main()
{
//    ios::sync_with_stdio(false);
    t = read();
    while (t--)
        solve();
    return 0;
}


