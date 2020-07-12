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

int t, num[maxn];
char str[maxn];
char Aim_str;
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d",&t);
    while (t--)
    {
        int len = 0;
        scanf(" %s", str);
        len = strlen(str);
        for (int i = 0; i< len; i++)
        {
        	if (str[i] == 'z')
        	{
        		str[i] = 'b';
        		break;
			}
			else if (str[i] == 'y')
			{
				continue;
			}
			break;
		}
		puts(str);

    }
    return 0;
}

