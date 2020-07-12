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
vector<pair<int, int > > res;
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


int t, len, q, n;
string str;
string str_exchange(string s, int l, int r)
{
    l--;
    r--;
//    cout << l << r <<endl;
    string temp;
    for (int i = l; i <= l + (r - l) / 2; i++)
    {
        temp[0] = s[i];
        s[i] = s[r - i + l];
        s[r - i + l] = temp[0];
    }
    return s;
}

string find_ans(int n, int q)
{
    string ans;
    int i = 0;
    for (i = 0; i < n / 2 - (q - 1); i++)
    {
        ans += '(';
    }
    for (; i < n - 2 * (q - 1); i++)
    {
        ans += ')';
    }
    for (; i < n; i++)
    {
        if (i & 1)
            ans += ')';
        else
            ans += '(';
    }
//    cout << ans <<endl;
    return ans;
}

void solve()
{
    res.clear();
    n = read();
    q = read();
    cin >> str;
    string ans = find_ans(n, q);
    int flag = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ans[i])
        {
            flag++;
            for (int j = i + 1; j < str.size(); j++)
            {
                if (str[j] != str[i])
                {
                    str = str_exchange(str, i + 1, j + 1);
//                    cout <<str <<endl;
                    res.push_back(make_pair(i + 1, j + 1));
                    break;
                }
            }
        }
    }
    cout << flag << endl;
    for (int i = 0; i < res.size(); i++)
    {

        cout << res[i].first << ' ' << res[i].second << endl;
    }
//    cout << str << endl;
}


int main()
{
//    ios::sync_with_stdio(false);
    t = read();
    while (t--)
    {
        solve();

    }
    return 0;
}

