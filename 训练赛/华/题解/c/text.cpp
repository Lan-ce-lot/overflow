/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:1.Ê÷µÄ±éÀú
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
const int maxn = 5000005;
int num[maxn];
string str;
int n, ans;
int main()
{
    while (cin >> n)
    {
        cin >> str;
        ans = 0;
        for (int i = 0; i < str.size() - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            if (num[a] == 1)
            {
                num[a] = 0;
            }
            else
            {
                ans += 1;
            }
            num[b] = 1;
        }
        cout << ans <<endl;
    }
    return 0;
}

