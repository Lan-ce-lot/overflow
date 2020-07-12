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
const int maxn = 1000005;

char str[maxn][40];
char tag[40];
int t, n;





int ans = 0;
int pos = 0;
void solve()
{
    scanf("%s", tag);
    int len = strlen(tag);
    char c = getchar();
    int i = 0;
    int tem = 0;
    while (~scanf("%s", str[i++]))
    {
//        puts(str[i - 1]);


        c = getchar();
        if (c == '\n')
            break;
    }
    for (int j = 0; j < i; j++)
    {
        int l = strlen(str[j]);
        if (l == len)
        {

            if (!strcmp(str[j], tag))
            {
                ans++;
                if (!pos)
                    pos = tem + 1 + j;
            }
            else
            {
                if (!strcmp(str[j] + 1, tag + 1) && (str[j][0] + 'a' - 'A' == tag[0] || str[j][0] + 'A' - 'a' == tag[0]))
                {
                    ans++;
                    if (!pos)
                        pos = tem + 1 + j;
                }
            }

        }
        tem += l;

    }
    if (ans)
    {

        cout << ans << ' ' << pos - 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}


int main()
{
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

/*
To
tt tt tt to tt

To
to tt tt tt to

to
to tt tt tt to

to
To tt tt tt to
*/
