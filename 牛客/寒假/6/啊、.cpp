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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;

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
string str;
double a, b, c;

double get(double a, double b, double c)
{
    double cos2s = (b * b + c * c - a * a) / (2.0 * b * c);
    double coss = sqrt((cos2s + 1) / 2.0);
    double sin2s = sqrt((1 - cos2s * cos2s));
    double sins = sin2s / coss / 2.0;
    double tans = sins / coss;
    return tans;
}

void solve()
{
//    map<char, char> M;
//    M['('] = ')';
//    cin >> t;
//    while(t--)
//    {
//        stack<int> s;
//        cin >> n;
//        cin >> str;
//        for (int i = 0; i < n; i++)
//        {
//            if (!s.empty() && M[s.top()] == str[i])
//            {
//                s.pop();
//            }
//            else
//            {
//                s.push(str[i]);
//            }
//        }
//        cout << s.size() << endl;
//    }
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a)
    {
        puts("Yes");
        double R = (sqrt((a + b - c) * (a - b + c ) * (b + c - a) / (a + b + c)) / 2.0);
        double r1[3];
        r1[0] = R / get(a, b, c);
        r1[1] = R / get(b, a, c);
        r1[2] = R / get(c, a, b);
        sort(r1, r1 + 3);
        for (int i = 0; i < 3; i++)
        {
            printf("%.2f ", r1[i]);
        }
        puts("");
    }
    else
    {
        puts("wtnl");
    }
}

int main()
{
    solve();
//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    return 0;
}

