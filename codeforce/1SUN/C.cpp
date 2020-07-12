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

string s, str1, str2, a;
int count1, count2;
int main()
{

//    cin >> a >> count1;
//    a[0] = 'A' + (a[0] + count1 - 'A') % 26;
//    cout << a;
    cin >> s;
    str1 = s.substr(0, s.size() / 2);
    str2 = s.substr(s.size() / 2, s.size());

//    cout << str1 << endl << str2 << endl;
    for (int i = 0; i < str2.size(); i++)
    {
        count1 += str1[i] - 'A';
        count2 += str2[i] - 'A';

        count1 %= 26;
        count2 %= 26;
    }

    for (int i = 0; i < str1.size(); i++)
    {
        str1[i] = 'A' + (str1[i] + count1 - 'A') % 26;

        str2[i] = 'A' + (str2[i] + count2 - 'A') % 26;


    }
    for (int i = 0; i < str1.size(); i++)
    {
        str1[i] = 'A' + (str1[i] + (str2[i] - 'A') - 'A') % 26;
    }
    cout << str1 << endl;




    return 0;
}

