/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description:
 ************************************************************************/
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:102400000,102400000")//add_stack
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
typedef pair<int, int> PII;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 1000005;
//sacnf("%lf") printf("%f")
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
int t, n, a[7];
int dp[1005][1005];
int ans = 0;
map<int, bool> M;
void solve()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	int temp = 0;
	map<int, bool> M;
	for (int i = 0; i <= a[0]; i++)
	{
		int temp = 0;
		for (int j = 0; j <= a[1]; j++)
		{
			for (int k = 0; k <= a[2]; k++)
			{
				for (int l = 0; l <= a[3]; l++)
				{
					for (int m = 0; m <= a[4]; m++)
					{
						for (int n = 0; n <= a[5]; n++)
						{
							temp = i * 1 + j * 2 + k * 3 + l * 5 + m * 10 + n * 20;
							M[temp] = 1;
						}
					}
				}
			}
		}
	}
	
	
	cout << "Total=" <<M.size() - 1 << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

