/*************************************************************************
 > FileName:
 > Author:      huangchangsheng
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int eps = 1e-10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;                             //int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 10005;
struct node
{
    int x, y, lx, ly;
} a[maxn];
int dp[maxn][maxn];
int pre[maxn][maxn], n, m, xx, yy;
bool test(int a, int b, int c, int d)
{
    if (a <= xx && b <= yy && c >= xx && d >= yy)
        return 1;
    return 0;

}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].lx, &a[i].ly);
    }
    scanf("%d%d", &xx, &yy);
    for (int i = n; i > 0; i--)
    {
        if (test(a[i].x, a[i].y, a[i].x + a[i].lx, a[i].y + a[i].ly))
        {
            printf("%d\n", i);
            return 0;
        }
        else
        {
            continue;
        }
    }
    puts("-1");
    return 0;
}

