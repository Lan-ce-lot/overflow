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

int t, n;int ans[maxn];
string str;
int tr()
{
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    puts("");
}

void solve()
{
    cin >> n;
    cin >> str;
    string ans = "";
    char ma = 'a', pma = 'a';
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= ma)
        {
            ma = max(str[i], ma);
            ans += '0';
        }
        else
        {
            if (str[i] >= pma)
            {
//                pma = str[i];
                pma = max(pma, str[i]);
                ans += '1';
            }
            else
            {
//                debug(i);
                puts("NO");
                return;
            }
        }
    }


    puts("YES");
    cout << ans << endl;



}

int main()
{
    solve();
//    ios::sync_with_stdio(false);
    return 0;
}

