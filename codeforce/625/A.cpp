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
int t, n;
int a[maxn];
map<ll, ll > M;
string str;
vector<int> G[27];

//bool test(int x)
//{
//	
//}

void solve()
{
	cin >> n;
	cin >> str;
	int ans = 0;
	
	for (int i = 0; i < n; i++)
	{
		G[str[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			if (G[i][j] != 0)
			{
				if (str[G[i][j] - 1] == char('a' + i - 1))
				{
					str = str.substr(0, G[i][j]) + str.substr(pos + 1, str.size() - 1 - G[i][j]);
					ans++;
					continue;
				}
			}
			
		}
	}
	//cout << *max_element(str.begin(), str.end());
//	for (int i = 0; i < 5000; i++)
//	{
//		
//		int pos = max_element(str.begin(), str.end()) - str.begin();
//		char c = *max_element(str.begin(), str.end());
//		if (c == 'a') break;
//		if (pos != 0)
//		{
//			if (str[pos - 1] == char(c - 1))
//			{debug(c - 1);
//				str = str.substr(0, pos) + str.substr(pos + 1, str.size() - 1 - pos);
//				ans++;
//				continue;
//			}
//		}
//		if (pos != str.size())
//		{
//			if (str[pos + 1] == c - 1)
//			{
//				str = str.substr(0, pos) + str.substr(pos + 1, str.size() - 1 - pos);
//				ans++;
//				continue;
//			}
//		}
//	}
	cout << ans << endl;
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

