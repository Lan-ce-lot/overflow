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

int main()
{
	int n, ans = -INF;
	n = read();
	for (int i = 0; i < n; i++)
		a[i] = read();
	ans = *max_element(a, a + n);
	if (ans < 0)
	{
		cout << ans << endl;
		return 0;
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + a[i] < 0)
			{
				sum = 0;
			}
			else
			{
				sum +=a[i];
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
    return 0;
}

