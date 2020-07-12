/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: ¶þÎ¬Ê÷×´Êý×éÄ£°å
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
const int maxn = 1010;

int m;
int num[maxn][maxn];
int treeNum[maxn][maxn];

int lowbit(int x)
{
    return x & (-x);
}
//%d%d*cºöÂÔ×Ö·û
int getsum(int x, int y)
{
    int sum = 0;
    for(int i = x ; i > 0 ; i -= lowbit(i))
        for(int j = y ; j > 0 ; j -= lowbit(j))
            sum += treeNum[i][j];
    return sum;
}

void add(int x, int y, int val)
{
    for(int i = x ; i < maxn ; i += lowbit(i))
        for(int j = y ; j < maxn ; j += lowbit(j))
            treeNum[i][j] += val;
}

int query(int x, int y, int xx, int yy)
{
    return getsum(xx, yy) - getsum(xx, y - 1) - getsum(x - 1, yy) + getsum(x - 1, y - 1);
}

int n, x, y, v, xx, yy, q;
char c;
int main()
{
//    ios::sync_with_stdio(false);
    scanf("%d", &n);
    while (n--)
    {
        getchar();
        c = getchar();
        if (c == 'B')
        {
            scanf("%d%d", &x, &y);
            x++, y++;
            if (!num[x][y])
                add(x, y, 1);
            num[x][y] = 1;
        }
        else if (c == 'D')
        {
            scanf("%d%d", &x, &y);
            x++, y++;
            if (num[x][y])
                add(x, y, -1);
            num[x][y] = 0;
        }
        else
        {
            scanf("%d%d%d%d", &x, &xx, &y, &yy);
            x++, y++, xx++, yy++;
            if (x > xx)
                swap(x, xx);
            if (y > yy)
                swap(y, yy);
//            int ans = getsum(xx, yy);
//            ans -= getsum(x - 1, yy);
//            ans -= getsum(xx, y - 1);
//            ans += getsum(x - 1, y - 1);
//            printf("%d\n",ans);
            printf("%d\n", query(x, y, xx, yy));
        }
    }
    return 0;
}
