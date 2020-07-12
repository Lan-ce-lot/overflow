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
int dp[maxn], a[maxn];
int coin_co[4];
int t, n;
int coin[4] = {10, 20, 50, 100};

//bool tx(int a[])
//{
//    if (a[0] <= 1 && a[1] <= 3 && a[2] <= 1 )
//        return 1;
//    return 0;
//}

bool test(int a)
{
    if ()
}


int res = 0, mm = 0, dd = 0;


bool dfs(int a)
{
    if (a >= coin[3])
    {
        if(test(a))
        {
            return 1;
        }
        dd = a / coin[3];
        mm = a % coin[3];
        coin_co[3] = max(coin_co[3], dd);
        dfs(mm);
    }
    else if( a >= coin[2])
    {
        dd = a / coin[2];
        mm = a % coin[2];
        coin_co[2] = 1;
        dfs(mm);
    }
    else if (a >= coin[1])
    {
        dd = a / coin[1];
        mm = a % coin[1];
        coin_co[1] = max(coin_co[1], dd);
        dfs(mm);
    }
    else if (a >= coin[0])
    {
        dd = a / coin[0];
        mm = a % coin[0];
        coin_co[0] = 1;
        dfs(mm);
    }
    else
    {
        return 0;
    }
    return 1;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        scanf("%d", &n);
        for (int i =0 ; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);

        int flag = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(dfs(a[i]) == 0)
            {
                flag = 1;
                break;
            }
        }
        for (int i = 0; i < 4; i++)
            sum += coin_co[i];
        flag ? puts("-1"):printf("%d\n", sum);
//        for (int i = 0; i < n; i++)
//        {
//            if (a[i] >= coin[3])
//            {
//                dd = a[i] / coin[3];
//                mm = a[i] % coin[3];
//                coin_co[3] = max(coin_co[3], dd);
//
//            }
//            else if( a[i] >= coin[2])
//            {
//                dd = a[i] / coin[2];
//                mm = a[i] % coin[2];
//                if ()
//                }
//            else if (a[i] >= coin[1])
//            {
//                dd = a[i] / coin[1];
//                mm = a[i] % coin[1];
//            }
//            else if (a[i] >= coin[0])
//            {
//                dd = a[i] / coin[0];
//                mm = a[i] % coin[0];
//            }
//            else
//            {
//                puts("-1");
//                break;
//            }
        }
//    ios::sync_with_stdio(false);
        return 0;
    }

