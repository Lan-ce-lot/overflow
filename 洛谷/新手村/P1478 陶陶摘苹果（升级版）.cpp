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
const int maxn = 10005;

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

struct node
{
	int x, y;
	bool operator< (const node &W)const
	{
		return y < W.y;
	}
}apple[maxn];

int t, n, s, a, b;
int main()
{
//    ios::sync_with_stdio(false);
//    freopen("F:/Overflow/in.txt","r",stdin);
	cin >>  n >> s >> a >> b;
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		if (a + b >= x)
		{
			apple[idx].x = x;
			apple[idx++].y = y;
		}
	}
	
	sort(apple, apple + idx);
	int res = 0;
	for (int i = 0; i < idx; s -= apple[i].y, i++)
	{
		if(s - apple[i].y >= 0)
		{
//			debug(apple[i].y);
			res++;
		}
			
	}
	cout << res << endl;
	
    return 0;
}

