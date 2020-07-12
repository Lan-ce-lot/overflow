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
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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
ULL t, n ,ans = 0;
string str;
map<char, ULL>M;
void solve()
{

    cin >> str;
    cin >> n;
    for (ll i = 0; i < str.size(); i++)
    {
        M[str[i]]++;
    }
    ULL MAX = 0;
//    for (auto i: M)
//        cout << i.first << ' ' << i.second <<endl;
    for (ll i = 0; i < str.size(); i++)
    {
        MAX = max(MAX, M[str[i]]);
    }
    ULL tem, len = 1;
    if (n <= str.size())
    {
        cout << 0 << endl;
        return ;
    }
    else if (n == str.size() + 1)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        n = n - str.size();
        tem = MAX;
        len = 0;
//        debug(tem);
    }
    while (n > len)
    {
        len += tem;
        ans++;
        if (len >= 9223372036854775808)//9223372036854775808
        {

            break;
        }



        tem *= 2;
    }
    cout << ans << endl;
}

int main()
{
   // freopen("F:/Overflow/in.txt","r",stdin);
    solve();

//    ios::sync_with_stdio(false);
    return 0;
}

