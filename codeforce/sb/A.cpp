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
int t, n, a[maxn], b[maxn], ans[maxn], res = 0;
string str;
void solve()
{
	cin >> str;
	for (int i = 0, j = str.size() - 1; i != j;i++, j--)
	{
		while (str[i] != '(' && i < str.size())
		{
			i++;
		}
		if (i >= j)
		{
			break;
		}
		
		
		while (str[j] != ')' && j >= 0)
		{
			j--;
		}
		
		
		if (i >= j)
		{
			break;
		}
		a[i] = 1;
		a[j] = 1;
		res += 2;
	}
	if (res == 0)
	{
		cout << 0 << endl;
		return ;
	}
	
	cout << 1 << endl << res << endl;
	for (int i = 0; i < str.size() && res; i++)
	{
		if (a[i])
		{
			cout << i + 1 << ' '; 
		}
		if (i == str.size() - 1)
		{
			puts("");
		}
	}
	
}

int main()
{

//    freopen("F:/Overflow/in.txt","r",stdin); 
//    ios::sync_with_stdio(false);
    solve();
    return 0;
}

