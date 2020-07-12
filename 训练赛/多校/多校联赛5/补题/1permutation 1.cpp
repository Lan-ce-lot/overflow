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
const int maxn = 25;
int a[maxn], t, count1 = 0, k, n;
struct node
{
    int f[25];
    int len;
}No[500005];

bool cmp(node a, node b)
{
    for (int i = 1; i < a.len; i++)
        if (a.f[i] - a.f[i - 1] != b.f[i] - b.f[i - 1])
            return a.f[i] - a.f[i - 1] < b.f[i] - b.f[i - 1];
}

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

int main()
{
    t = read();
    while(t--)
    {
        n = read();
        k = read();
        int pos = 0;
        if (n < 9)
        {
            for (int i = 0; i < n; i++)
                a[i] = i + 1;
            do
            {
                pos++;
                for (int i = 0; i < n; i++)
                    No[pos].f[i] = a[i];
            }while(next_permutation(a,a + n));
        }
        else
        {
            for (int i = 0, j = 8; i < 8; i++, j--)
                a[i] = n - j;

            do
            {
                pos++;
                No[pos].f[0] = n;
                for (int i = 1; i < n - 8; i++)
                    No[pos].f[i] = i;
                for (int i = n - 8, j = 0; i < n; i++, j++)
                    No[pos].f[i] = a[j];
            }while(next_permutation(a, a + 8));
        }
        for (int i = 1; i <= pos; i++)
            No[i].len = n;
        sort(No + 1, No + pos + 1, cmp);
        for (int i = 0; i < n; i++)
            printf(i < n - 1?"%d ":"%d\n", No[k].f[i]);
    }
    return 0;
}
