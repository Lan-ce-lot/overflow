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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 5001;
//sacnf("%lf") printf("%f")
ll read()
{
    ll x = 0, f = 1;
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
    unordered_map<string, string> M;
    M["1"] = "2";
    debug(M.count("2"));
    string str;
    while (getline(cin, str))
    {
        string s1, s2;
        if (str == "")
        {
//            debug(1);
            break;
        }
//        str.find(' ');
//        cout << (str.find(' ')) << endl;
        s1 = str.substr(0, str.find(' '));
        s2 = str.substr(str.find(' ') + 1, str.size() - str.find(' ') - 1);
        M[s2] = s1;
    }
    while (getline(cin, str))
    {
        if (str == "")
            break;
        if (M.count(str))
        {
            cout << M[str] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }
}

int main()
{

    //    freopen("F:/Overflow/in.txt","r",stdin);
    //    ios::sync_with_stdio(false);
    solve();
    return 0;
}

