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
const int maxn = 10025;
int t, n;
char str[maxn][maxn] = {{'C', 'C'}, {'P', 'C'}};
int main()
{
    for (int i = 2; i <= 10; i++)
    {
        for (int j = 0; j < (1 << i); j++)
        {
            for (int k = 0; k < (1 << i); k++)
            {
                if (k >= 1 << (i - 1) )
                    if (j < 1 << (i - 1))
                        str[j][k] = str[j][k - (1 << (i - 1))];
                    else
                        str[j][k] = str[j- (1 << (i - 1))][k];
                else if (j >= (1 << (i - 1)) && k < (1 << (i - 1)))
                    if (str[j - (1 << (i - 1))][k] == 'C')
                        str[j][k] = 'P';
                    else
                        str[j][k] = 'C';
//                printf(k == (1 << i) - 1 ? "%c\n" : "%c ", str[j][k]);
            }
        }
//        puts("");
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < 1 << n; i++)
            for (int j = 0 ; j < 1 << n; j++)
                printf(j == (1 << n) - 1 ? "%c\n" : "%c", str[i][j]);
    }
    return 0;
}
//93MS	6508K
