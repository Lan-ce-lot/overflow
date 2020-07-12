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
const int maxn = 1e5 + 5;//找交点

struct node
{
    int x, y;
    char dir;
    node(int _x = 0,int _y = 0, char _dir = '0') : x(_x), y(_y), dir(_dir) {}
};
node a[maxn];

//ans = 与边重合的点+交点+1,
//题目说并且没有两个切割共享相同的x坐标或y坐标
//若两条线反向且有重合交集，合并；若两条线同向有重合交集，合并;
int t, n, x, y;
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        int dflag1 = 0, dflag2 = 0;//0上下
        scanf("%d%d%d", &x, &y, &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d %c", &a[i].x, &a[i].y, &a[i].dir);
        }

        for (int i = 0 ; i< n; i++)
        {
            dflag1 = a[i].dir == 'U' || a[i].dir == 'D' ? 0 : 1;
            for (int  j = 0; j < n; j++)
            {
                dflag2 = a[j].dir == 'U' || a[j].dir == 'D' ? 0 : 1;
                if (dflag1 != dflag2)
                {
                    if (dflag1 == 0)
                    {
                        if (a[i].dir == 'U')
                            a[j].y > a[i].y ? ans++ : ans;
                        else
                            a[j].y < a[i].y ? ans++ : ans;
                    }
                    else
                    {
                        if (a[i].dir == 'L')
                            a[i].x > a[j].x ? ans++ : ans;
                        else
                            a[i].x < a[j].x ? ans++ : ans;
                    }
                }
            }
        }
        printf("%d\n", (ans + 2) / 2);
    }
    return 0;
}


