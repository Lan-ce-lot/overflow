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
const int maxn = 1005;
int a[maxn];
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
ll t, n;
int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        ll ans1 = 0, ans2 = 0;
        scanf("%lld", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);

        }
        sort(a, a + n);
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(flag)
            {
                ans1 += a[i];
                flag = 0;
            }
            else
            {
                ans2 += a[i];
                flag = 1;
            }
        }
        cout << ans2 << ' ' <<ans1 <<endl;
    }
    return 0;
}

