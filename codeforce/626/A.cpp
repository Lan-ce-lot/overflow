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
int b[maxn];
string str;
int l = 0, r = 0, ans = 0;
void solve()
{
	stack<char> S;
	int res = 0;
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			l++;
			
		}
		else
		{
			r++;
		}
	}
	int temp_l = 0, temp_r = 0, star = 0;

	if (l == r)
	{
		for (int i = 0; i < n; i++)
		{
//			cout << temp_l << ' ' << temp_r <<endl;
			if (str[i] == '(')
			{
				temp_l++;
				S.push('(');
				
			}
			else
			{
				temp_r++;
				if (!S.empty())
				{
					if (S.top() == '(')
					{
						S.pop();
					}
					else
					{
						S.push(')');
					}
				}
				else
				{
					S.push(')');
				}
			}
			
			if (temp_l == temp_r )
			{

		//			debug(ans);
//		debug(i);
//		debug(star);
					ans += (S.size() == 0 ? 0 : i + 1 - star);
					while (S.size())
					{
						S.pop();
					}
				star = i + 1;
			}
		}
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
		
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin);
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}
/*
8
)(()())(

*/
