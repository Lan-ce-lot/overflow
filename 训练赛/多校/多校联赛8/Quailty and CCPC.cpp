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
const int maxn = 1e6 + 5;
struct node
{
    int x_, y_, a, b;
}ran[3];

int t, n, d, x, xx, y, yy, x2, xx2, y2, yy2;
int main()
{
    scanf("%d", &t);
    while (t--)
    {

        scanf("%d%d%d%d", &x, &y, &xx, &yy)
        ran[0].x_ = min(x, xx);
        ran[0].y_ = min(y, yy);
        ran[0].a = abs(xx - x);
        ran[0].b = abs(yy - y);
        scanf("%d%d%d%d", &x2, &y2, &xx2, &yy2);
        ran[1].x_ = min(x, xx);
        ran[1].y_ = min(y, yy);
        ran[1].a = abs(xx - x);
        ran[1].b = abs(yy - y);
        if (a[0].x_ > a[1].x_ &&a[0].y_ >a[1].y_)
        {


        }
        else if()
        {

        }
        printf("%d\n", ans);
    }
    return 0;
}
