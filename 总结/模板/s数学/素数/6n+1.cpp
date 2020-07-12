/*************************************************************************
 > File Name:
 > Author:  huangchangsheng
 > Mail:
 > Time:    19-7-07
 > Desc:    素数分布的应用，素数定理的推论：令Pn是第n个素数，其中n是正整数，那么Pn ~ nln n;
 题目是指10的n次方，输出是素数个数的位数
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
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1005;
int prime[maxn], k = 0;
bool isprime[int k]
{
    if (k == 2)
        return true;
    if (k % 2 == 0)
        return false;
    for (int i = 3; i * i <= k; i += 2)
    {
        if (!(k % i))
        {
            return false;
        }
    }
    return true;
}

void doprime()
{
    for (int i = 1; i <= maxn; i += 3)
    {
        for (int j = 0;j < 2; j++)
        {
            if ()

        }

    }
}
int a[maxn];
int main()
{

    return 0;
}
