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
struct node
{
    int v, index;
}a[maxn];


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
map<int, int> change;
int t, n, q, f, b;
int main()
{
//    ios::sync_with_stdio(false);
    n = read();
    q = read();
    int cnt = 0;
    while (q--)
    {
        f = read();
        b = read();
        if (f == 1)
        {
            if (change[b + 1] == 0)
                change[b] = b + 1;
            else
            {

                change[b] = change[b + 1];
                change[b - 1] = change[b];
            }

        }
        else
        {
            if (change.find(b) != change.end())
            {
                if(change[b + 1] != 0)
                    change[b] = change[b + 1];
                printf("%d\n", change[b]);
            }
            else
            {
                printf("%d\n", b);
            }
        }
    }

    return 0;
}

