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
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;//int2147483647//ll9e18//unsigned ll 1e19
const int maxn = 100005;

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
int t, n;
int prime[maxn], idx = 0;
bool vis[maxn];
void get_prime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i]) prime[idx++] = i;
		for (int j = 0; prime[j] <= n / i; j++)
		{
			vis[prime[j] * i] = 1;
			if (i % prime[j] == 0) break;
			
		}
		
	}
	
}



int main()
{
//    ios::sync_with_stdio(false);
	cin >> n;
	get_prime(n);
	vis[0] = 1;
	vis[1] = 1;
	for (int i = 2; i < n; i++)
	{
		if (vis[i]) continue;
		for (int j = i; j < n; j++)
		{
			if (vis[j]) continue;
			int k = n - i - j;

				if (vis[k]) continue;
				else
				{
					cout << i << ' ' << j << ' ' << k << endl;
					return 0;
				}
			
		}
		
	}
    return 0;
}

