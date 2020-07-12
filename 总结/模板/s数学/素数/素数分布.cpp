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

int a[maxn];
int main()
{
    int out;
    double n, m;
    while(cin >> n)
    {
        m = double(n - log10(n) - log10(log(10)));//求（n / ln n）的位数
        cout << int(m) + 1 << endl;

    }
    return 0;
}
