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


int t, n;
string str1, str2, str_taget;
void bfs()
{
    string s1 = str1;
    string s2 = str2;
    string temp;
    int ans = 0;
    while (temp != str_taget)
    {
        temp = "";
        ans ++;
        for (int i = 0; i < s1.size(); i++)
        {
            temp += s2[i];
            temp += s1[i];
        }
        s1 = temp.substr(0, s1.size());
        s2 = temp.substr(s1.size(), s1.size());
        if (s1 == str1 && s2 == str2)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
    return;
}

void solve()
{
    cin >> t;
    int cont = 0;
    while (t--)
    {
        cin >> n;

        cin >> str1 >> str2 >> str_taget;
        cont ++;
        cout << cont << ' ';
        bfs();
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

