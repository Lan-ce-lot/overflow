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
ll t, n, a, b, c, d, ans = 0, ans1 = 0;
string str;
map<char, int> M;
void solve()
{
    cin >> t;
    while (t--) {
        M.clear();
        ans = 0;
        cin >> str;
        for (int i = 0; i < str.size(); i++) {
            M[str[i]]++;
        }
        if (M['1'] == 0 || M['3'] == 0 || M['2'] == 0) {
            cout << 0 <<endl;
            continue;
        }
        int len = str.size();
        string tem;
        for (int i = 0; i < len; i++) {
            if (M[str[i]] > 1) {
                M[str[i]] --;
            } else {
//                debug(i);
                ans += i;
                break;
            }
        }
        reverse(str.begin(), str.end());
        for (int i = 0; i < len; i++) {
            int to = 0;
            if (M[str[i]] > 1) {
                M[str[i]] --;
            } else {
                ans += i;
                break;
            }
        }


        ans = len - ans;


        //================================
        M.clear();
        ans1 = 0;
        for (int i = 0; i < str.size(); i++) {
            M[str[i]]++;
        }
        if (M['1'] == 0 || M['3'] == 0 || M['2'] == 0) {
            cout << 0 <<endl;
            continue;
        }
        int len1 = str.size();
        for (int i = 0; i < len; i++) {
            if (M[str[i]] > 1) {
                M[str[i]] --;
            } else {
//                debug(i);
                ans1 += i;
                break;
            }
        }
        reverse(str.begin(), str.end());
        for (int i = 0; i < len; i++) {
            int to = 0;
            if (M[str[i]] > 1) {
                M[str[i]] --;
            } else {
                ans1 += i;
                break;
            }
        }


        ans1 = len - ans1;
        cout << min(ans1, ans) << endl;

    }
}
/*
100
311111213111211113
*/
int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

